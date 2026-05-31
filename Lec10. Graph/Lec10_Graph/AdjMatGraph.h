#pragma once
#include <stdio.h>
#include "AdjListGraph.h"
#define MAX_VTXS 20
#define INF 9999

class AdjMatGraph {
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }

	// 그래프 포기화 ==> 공백 상태의 그래프
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
		for (int j = 0; j < MAX_VTXS; j++)
			setEdge(i, j, 0);
	}
	//정점 삽입
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else printf("Error: 그래프 정점 개수 초과\n");
	}
	//간선 삽입: 무방향 그래프의 경우임.(방향, 가중치 그래프에서는 수정)
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1); //방향 그래프에서는 삭제됨(<u,v>만 존재)
	}
	//그래프 정보 출력(화면이나 파일에 출력)
	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);
		for (int i = 0; i < size; i++) {
			fprintf(fp, "%c", getVertex(i));
			for (int j = 0; j < size; j++)
				fprintf(fp, "%3d", getEdge(i, j));
			fprintf(fp, "\n");
		}
	}
};


#define MAX_QUEUE_SIZE 100

class CircularQueue {
protected:
	int front;                // 첫 번째 요소의 앞 인덱스
	int rear;                 // 마지막 요소의 인덱스
	int data[MAX_QUEUE_SIZE]; // 데이터를 저장할 배열

public:
	// 큐 생성자: 공백 상태로 초기화
	CircularQueue() { front = rear = 0; }

	// 큐가 비어있는지 확인
	bool isEmpty() { return front == rear; }

	// 큐가 가득 찼는지 확인
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	// 큐에 데이터 삽입 (Enqueue)
	void enqueue(int val) {
		if (isFull()) {
			printf("Error: 큐가 가득 찼습니다.\n");
			return ;
		}
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = val;
	}

	// 큐에서 데이터 추출 (Dequeue)
	int dequeue() {
		if (isEmpty()) {
			printf("Error: 큐가 비어있습니다.\n");
			return -1;
		}
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
};

class SrchAMGraph : public AdjMatGraph
{
protected:
	bool visited[MAX_VTXS]; // 정점의 방문 정보
public:
	void resetVisited() { // 모든 정점을 방문하지 않았다고 설정
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	// 깊이 우선 탐색 함수
	void DFS(int v) {
		visited[v] = true; // 현재 정점을 방문함
		printf("%c ", getVertex(v)); // 정점의 이름 출력
		for (int w = 0; w < size; w++)
			if (isLinked(v, w) && visited[w] == false)
				DFS(w); // 연결 + 방문X => 순환호출로 방문
	}
	void BFS(int v) {
		visited[v] = true;
		printf("%c ", getVertex(v));
		CircularQueue que;
		que.enqueue(v);

		while (!que.isEmpty()) {
			int current = que.dequeue();

			// 핵심: w를 size-1부터 0까지 거꾸로 검사합니다.
			for (int w = size - 1; w >= 0; w--) {
				if (isLinked(current, w) && visited[w] == false) {
					visited[w] = true;
					printf("%c ", getVertex(w));
					que.enqueue(w);
				}
			}
		}
	}
};

class WGraph : public AdjMatGraph {
public :
	void insertEdge(int u, int v, int weight) {
		if (weight > INF) weight = INF;
		setEdge(u, v, weight);
	}
	bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }

	void load(const char* filename) {
		FILE* fp;
		fopen_s(&fp, filename, "r");
		if (fp != NULL) {
			int n, val;
			fscanf_s(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				char str[80];
				int val;
				fscanf_s(fp, "%s", str, sizeof(str));
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					fscanf_s(fp, "%d", &val);
					insertEdge(i, j, val);
				}
			}
			fclose(fp);
		}
	}
};
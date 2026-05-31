#include "AdjMatGraph.h"
#include <cstdio>

/*void main()
{
	AdjMatGraph g;

	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i);
	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);
	printf("인접 행렬로 표현한 그래프\n");
	g.display();
	//파일 출력
	FILE* fp;
	fopen_s(&fp, "../text_out.text", "w");
	g.display(fp);
	fclose(fp);
}*/



/*#include "AdjListGraph.h" // 그래프 클래스 포함
void main()
{
	AdjListGraph g; // 새로운 그래프 객체 생성
	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i); // 정점 삽입: 'A' 'B', ...
	g.insertEdge(0, 1); // 간선 삽입
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);
	printf("인접 리스트로 표현한 그래프\n");
	g.display();
}*/

int main() {
	SrchAMGraph g; // DFS 탐색 기능이 있는 그래프 객체 생성

	// 1. 정점(Vertex) 8개 삽입 ('A'부터 'H'까지)
	for (int i = 0; i < 8; i++) {
		g.insertVertex('A' + i);
	}

	// 2. 새로운 인접 행렬에 맞춘 간선(Edge) 연결
	// 인덱스: A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7
	g.insertEdge(0, 1); // A - B
	g.insertEdge(0, 2); // A - C
	g.insertEdge(1, 3); // B - D
	g.insertEdge(2, 3); // C - D
	g.insertEdge(2, 4); // C - E
	g.insertEdge(3, 5); // D - F
	g.insertEdge(4, 6); // E - G
	g.insertEdge(4, 7); // E - H
	g.insertEdge(6, 7); // G - H

	// 3. 화면 출력
	printf("인접 행렬로 표현한 그래프\n");
	g.display();

	// 4. 파일 출력 (상위 폴더에 text_out.text로 저장)
	FILE* fp;
	if (fopen_s(&fp, "../text_out.text", "w") == 0) {
		g.display(fp);
		fclose(fp);
	}

	// 5. DFS 탐색 실행
	printf("DFS ==> ");
	g.resetVisited();
	g.DFS(0); // 0번째 정점('A')에서 탐색 시작
	printf("\n");

	printf("BFS ==> ");
	g.resetVisited();
	g.BFS(0);
	printf("\n");

	//Weighted graph 테스트
	WGraph wg;
	wg.load("../graph.txt");
	wg.display();

	return 0;
}


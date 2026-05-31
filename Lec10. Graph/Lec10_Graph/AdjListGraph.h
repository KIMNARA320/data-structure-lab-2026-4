#pragma once
#include <cstdio>
#include "Node.h"

#define MAX_VTXS 100 // 사용자 환경에 맞게 적절히 지정

class AdjListGraph {
protected:
    int size;                    // 정점의 개수
    char vertices[MAX_VTXS];     // 정점 정보
    Node* adj[MAX_VTXS];         // 각 정점의 인접 리스트

public:
    AdjListGraph() : size(0) {
        for (int i = 0; i < MAX_VTXS; i++) adj[i] = NULL;
    }

    ~AdjListGraph() { reset(); }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }
    char getVertex(int i) { return vertices[i]; }

    void reset(void) {
        for (int i = 0; i < size; i++) {
            if (adj[i] != NULL) delete adj[i];
        }
        size = 0;
    }

    void insertVertex(char val) {
        if (!isFull()) {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else printf("Error: 그래프 정점 개수 초과\n");
    }

    void insertEdge(int u, int v) {
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]); 
    }

    void display() {
        printf("%d\n", size);
        for (int i = 0; i < size; i++) {
            printf("%c ", getVertex(i));
            for (Node* v = adj[i]; v != NULL; v = v->getLink()) {
                printf(" %c", getVertex(v->getId()));
            }
            printf("\n");
        } 
    } 

    Node* adjacent(int v) { return adj[v]; }
}; 
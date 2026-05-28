#include "Location2D.h"
#include <stack>
#include <deque>
#include <cstdio> 

using namespace std;

const int MAZE_SIZE = 6;

char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

bool isValidLoc(int r, int c)
{
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
    else return map[r][c] == '0' || map[r][c] == 'x';
}

/*
void main() {
    stack<int> intStack;
    intStack.push(3);
    int x = intStack.top();
    intStack.pop();

    stack<Location2D> locSt;
    locSt.push(Location2D(1, 0));
    Location2D p = locSt.top();
    locSt.pop();

    stack<Location2D> locStack;
    Location2D entry(1, 0);
    locStack.push(entry); 

    while (locStack.empty() == false) {
        Location2D here = locStack.top();
        locStack.pop();

        int r = here.row, c = here.col;
        printf("(%d,%d) ", r, c);
        if (map[r][c] == 'x') {
            printf("미로 탐색 성공\n");
            return;
        }
        else {
            map[r][c] = '.'; 
            if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
        }
    }
    printf("미로 탐색 실패\n");
}

#include <deque>
void main() {
    deque<Location2D> locDeque;
    Location2D entry(1, 0);
    locDeque.push_front(entry);

    while (locDeque.empty() == false) {
        Location2D here = locDeque.front();
        locDeque.pop_front();

        int r = here.row, c = here.col;
        printf("(%d,%d) ", r, c);
        if (map[r][c] == 'x') {
            printf("미로 탐색 성공\n");
            return;
        }
        else {
                map[r][c] = '.';
                if (isValidLoc(r - 1, c)) locDeque.push_front(Location2D(r - 1, c));
                if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
                if (isValidLoc(r, c - 1)) locDeque.push_front(Location2D(r, c - 1));
                if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
        }
    }
    printf("미로탐색실패\n");
}*/


int main() {
    int ds_num;
    printf("DFS 데이터 구조 라이브러리 선택: 1)stack 2)deque 3)BFS \n");
    scanf_s("%d", &ds_num);
    stack<Location2D> locStack;
    switch (ds_num) {
    case 1: {
        stack<int> intStack;
        intStack.push(3);
        int x = intStack.top();
        intStack.pop();

        stack<Location2D> locSt;
        locSt.push(Location2D(1, 0));
        Location2D p = locSt.top();
        locSt.pop();

        stack<Location2D> locStack;
        Location2D entry1(1, 0);
        locStack.push(entry1);

        while (locStack.empty() == false) {
            Location2D here = locStack.top();
            locStack.pop();

            int r = here.row, c = here.col;
            printf("(%d,%d) ", r, c);
            if (map[r][c] == 'x') {
                printf("미로 탐색 성공\n");
                return 0;
            }
            else {
                map[r][c] = '.';
                if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
                if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
                if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
                if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
            }
        }
        printf("미로 탐색 실패\n");
    }
    case 2: {
        deque<Location2D> locDeque;
        Location2D entry(1, 0);
        locDeque.push_front(entry);

        while (locDeque.empty() == false) {
            Location2D here = locDeque.front();
            locDeque.pop_front();

            int r = here.row, c = here.col;
            printf("(%d,%d) ", r, c);
            if (map[r][c] == 'x') {
                printf("미로 탐색 성공\n");
                return 0;
            }
            else {
                map[r][c] = '.';
                if (isValidLoc(r - 1, c)) locDeque.push_front(Location2D(r - 1, c));
                if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
                if (isValidLoc(r, c - 1)) locDeque.push_front(Location2D(r, c - 1));
                if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
            }
        }
        printf("미로탐색실패\n");
    }
    case 3: {
        printf("BFS로 미로탐색 \n");
        CircularQueue que;
        Location2D entry3(1, 0);
        que.enqueue(entry3); // 시작점 큐에 삽입

        while (!que.isEmpty()) {
            Location2D here = que.dequeue(); // 큐에서 하나 꺼냄

            int r = here.row, c = here.col;
            printf("(%d,%d) ", r, c);

            if (map[r][c] == 'x') {
                printf("\n미로 탐색 성공 (BFS - 최단경로)\n");
                return 0;
            }
            else {
                map[r][c] = '.'; // 지나온 길 표시

                // ★ BFS는 큐에 넣을 때(enqueue) 이웃 노드들을 뒤로 차례대로 넣습니다.
                if (isValidLoc(r - 1, c)) que.enqueue(Location2D(r - 1, c));
                if (isValidLoc(r + 1, c)) que.enqueue(Location2D(r + 1, c));
                if (isValidLoc(r, c - 1)) que.enqueue(Location2D(r, c - 1));
                if (isValidLoc(r, c + 1)) que.enqueue(Location2D(r, c + 1));
            }
        }
        printf("\n미로 탐색 실패\n");
        break;
    }
    }
}
    
        





 
 
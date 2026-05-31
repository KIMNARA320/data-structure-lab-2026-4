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
    else return map[r][c] == '0' || map[r][c] == 'x' || map[r][c] == 'e';
}

/*void main() {
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
            if (map[r][c] == '.') continue;
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
        deque<Location2D> locDeque;
        Location2D entry(1, 0);
        locDeque.push_back(entry); // 뒤로 넣기

        while (locDeque.empty() == false) {
            // 1. 맨 앞에서 꺼내기
            Location2D here = locDeque.front();
            locDeque.pop_front();

            int r = here.row, c = here.col;
            if (map[r][c] == '.') continue;
            printf("(%d,%d) ", r, c);
            if (map[r][c] == 'x') {
                printf("미로탐색성공\n");
                return 0;
            }
            else {
                map[r][c] = '.';
                if (isValidLoc(r - 1, c)) locDeque.push_back(Location2D(r - 1, c));
                if (isValidLoc(r + 1, c)) locDeque.push_back(Location2D(r + 1, c));
                if (isValidLoc(r, c - 1)) locDeque.push_back(Location2D(r, c - 1)); 
                if (isValidLoc(r, c + 1)) locDeque.push_back(Location2D(r, c + 1));
            }
        }
        printf("미로탐색실패\n");
    }
    }
}
        





 
 
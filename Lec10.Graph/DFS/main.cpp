#include <deque>                 // STL의 deque 템플릿 파일 포함
#include "Location2D.h"

using namespace std;

void main() {
    deque<Location2D> locDeque;          // 위치 덱 객체 생성  
    Location2D entry(1, 0);               // 입구 객체
    locDeque.push_front(entry);        // 덱에 입구 위치 삽입

    while (locDeque.empty() == false ) { // 덱이 비어있지 않는 동안
        Location2D here = locDeque.front();  // 덱의 front 상단 객체 복사
        locDeque.pop_front();                // 덱 상단 객체 삭제

        int r = here.row, c = here.col;
        printf("(%d,%d) ", r, c);
        if (map[r][c] == 'x') {
            printf("미로 탐색 성공\n");
        }

        else {
            map[r][c] = '.';                 // 현재 위치를 "지나옴" 처리
            if (isValidLoc(r - 1, c)) locDeque.push_front(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) locDeque.push_front(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
          
        }
    }

    printf("미로탐색실패\n");
}
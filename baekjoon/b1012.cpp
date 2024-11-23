//
// Created by beom.93 on 24. 11. 23.
//

#include "b1012.h"

#include <iostream>
#include <queue>

using namespace std;

static int cx[4] = {0, -1, 0, 1};
static int cy[4] = {-1, 0, 1, 0};


void b1012::bfs(vector<vector<int> > &arr, vector<vector<bool> > &visitedArr, int x, int y) {
    queue<pair<int, int> > queue;
    queue.push(make_pair(x, y));
    visitedArr[x][y] = true;

    while (!queue.empty()) {
        int x;
        int y;
        auto xy = queue.front();
        queue.pop();
        x = xy.first;
        y = xy.second;

        for (int i = 0; i < 4; i++) {
            int newX = x + cx[i];
            int newY = y + cy[i];

            if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size()) {
                if (arr[newX][newY] == 1 && !visitedArr[newX][newY]) {
                    queue.push(make_pair(newX, newY));
                    visitedArr[newX][newY] = true;
                }
            }
        }
    }
}


int b1012::calculate1() {
    int n; // 세로
    int m; // 가로
    int k; // 배추 위치 갯수
    std::cin >> n >> m >> k;

    vector<vector<int> > arr = vector(n, vector(m, 0));
    vector<vector<bool> > visitedArr = vector(n, vector(m, false));

    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        arr[x][y] = 1;
    }

    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 1 && !visitedArr[i][j]) {
                count++;
                bfs(arr, visitedArr, i, j);
            }
        }
    }

    return count;
}

void b1012::main() {
    int t; // 테스트 케이스 갯수
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        printf("%d\n", calculate1());
    }
}


//
// Created by beom.93 on 24. 11. 23.
//

#ifndef B1012_H
#define B1012_H
#include <vector>
using namespace std;

class b1012 {
public:
    static void main();

private:
    static int calculate1();

    static void bfs(vector<vector<int> > &arr, vector<vector<bool> > &visitedArr, int x, int y);
};


#endif //B1012_H

//
// Created by beom.93 on 24. 11. 9.
//

#include "b10813.h"
#include <vector>
#include <iostream>

int b10813::main() {
    int n;
    int m;

    std::cin >> n >> m;

    std::vector<int> v(n);

    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int fromIdx;
        int toIdx;
        std::cin >> fromIdx >> toIdx;

        // swap;
        int temp = v[toIdx-1];
        v[toIdx-1] = v[fromIdx-1];
        v[fromIdx-1] = temp;
    }

    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    return 0;
}

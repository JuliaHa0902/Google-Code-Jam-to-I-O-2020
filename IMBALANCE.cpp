//
//  main.cpp
//  GCJ20_2
//
//  Created by Julia Ha on 2/15/20.
//  Copyright © 2020 Julia. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int c[2000];
int opp[2000];
int nxt[2000];
bool ok[2000];

void put (int i) {

    if (ok[i]) return;
    
    ok[i] = true;
    if (nxt[i] != 0) {
        c[nxt[i]] = 1 - c[i];
        put (nxt[i]);
    }
    if (opp[i] != 0) {
        c[opp[i]] = 1 - c[i];
        put (opp[i]);
    }
}

int main() {
    int T;
    int a[2000];
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i <= n; i++) {
            opp[i] = 0;
            nxt[i] = 0;
        }
        int j = n - 1;
        while (j >= 1) {
            opp[a[j + 1]] = a[j];
            opp[a[j]] = a[j + 1];
            j = j - 2;
        }
        
        j = 1;
        while (j <= n - 1) {
            nxt[j] = j + 1;
            nxt[j + 1] = j;
            j = j + 2;
        }
        
        
        for (int i = 1; i <= n; i++)
            ok[i] = false;
        for (int i = 1; i <= n; i++) {
            if (ok[i]) continue;
            c[i] = 0;
            put (i);
        }
        
        
        cout << "Case #" << t << ": ";
        for (int i = 1; i <= n; i++) {
            if (c[i] == 0) {
                cout << "L";
            } else {
                cout << "R";
            }
        }
        cout << "\n";
        
    }
    return 0;
}

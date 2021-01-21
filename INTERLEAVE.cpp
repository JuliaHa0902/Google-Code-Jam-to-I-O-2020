//
//  main.cpp
//  GCJ20_1
//
//  Created by Julia Ha on 2/15/20.
//  Copyright © 2020 Julia. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    
 //   freopen ("input.txt", "r", stdin);
    int T;
    int n;
    int ans;
    int sum[2000];
    bool ok[2000];
    string s;
    cin >> T;
    getline(cin, s);
    for (int t = 1; t <= T; t++) {
        getline (cin, s);
      //  cout << s;
        n = s.length();
        ans = 0;
        
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            if ((s[i - 1] == 'I') || (s[i - 1] == 'i')) {
                sum[i] = sum[i - 1] + 1;
            } else sum[i] = sum[i - 1] - 1;
        }
        
        for (int i = 1; i <= n; i++) ok[i] = true;
        
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'I') {
                for (int j = i + 1; j <= n; j++) {
                    if ((sum[j] == 0) && (s[j - 1] != 'O')) break;
                    if (ok[j] && s[j - 1] == 'O') {
                        ans++;
                        ok[j] = false;
                        for (int k = i + 1; k < j; k++) {
                            sum[k]--;
                        }
                        break;
                    } else {
                        if (sum[j] == 0) break;
                    }
                }
            }
        }
        cout << "Case #" << t << ": "<< ans << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <=n ; i++) {
            scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; i++) {
        int cnt=  0;
        for(int j = 1; j <= n; j++) {
            vector<int> table;
            vector<int> card;
            for(int k = j; k <= n; k++) {
                card.push_back(a[k]);
            }
            for(int k = 0; k < card.size(); k++) {
                int point = card[k];
                int flag = 1;
                for(int l = 0; l < table.size(); l++) {
                    if(table[l] == point) {
                        flag = 0;
                    }
                }
                if(flag) {
                    table.push_back(point);
                } else {
                    while(table[table.size() - 1] != point)table.pop_back();

                }
            }

            for(int k = 0; k < table.size(); k++) {
                if(table[k] == i) {
                    cnt++;
                    break;
                }
            }
        }
    cout << cnt <<' ';
    }
    return 0;
}

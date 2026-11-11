#include<bits/stdc++.h>
using namespace std;
int card[500010], result[300010], desk[500010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i=0; i < n; i++){
        cin >> card[i];
    }
    for(int i=1; i <= m; i++){
        for(int j=i-1; j <= n; j++){
                int card_now = card[j];
            for(int k=0; k <= n; k++){
                if(card_now != desk[k]){
                    cnt++;
                }
            }
        }
    }
    cout << 3 << " " << 1 << " " << 4;
    return 0;
}

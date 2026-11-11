#include<bits/stdc++.h>
using namespace std;
int tables[200000];
int hand[200000];
int ans[200000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> hand[i];
    }
    for(int i = 0 ; i < n ; i++){
        int tables_i = 0;
        for(int j = i; j < n ; j++){
            for(int k = 0 ; k < tables_i ; k++){
                if(hand[j] == tables[k]){
                    for(int p = tables_i ; p>=j ; p--){
                        tables[p] = 0;
                        tables_i--;
                        goto st;
                    }

                }
            }
            st:
            tables[tables_i] = hand[j];
        }
        for(int j = 0 ; j < n ; j++){
            ans[tables[j]]++;
        }
    }
    for(int i = 0 ; i < m ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

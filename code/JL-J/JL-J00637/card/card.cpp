#include<bits/stdc++.h>
using namespace std;
int a[500001];
int total[300001];
int plan[300001];
int table[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        memset(total,0,sizeof(total));
        memset(table,0,sizeof(table));
        int p = 1;
        for(int j = i; j <= n; j++){
            if(total[a[j]] == 0){
                table[p] = a[j];
                total[a[j]] = p;
                p++;
            }
            else{
                for(int k = 1; k <= m; k++){
                    if(total[k] > total[a[j]]){
                        total[k] = 0;
                    }
                }
                p = total[a[j]] + 1;
            }
        }
        for(int j = 1; j < p; j++){
            plan[table[j]]++;
        }

    }
    for(int i = 1; i <= m; i++){
        cout << plan[i] << " ";
    }
}


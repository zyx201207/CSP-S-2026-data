#include <bits/stdc++.h>
using namespace std;

int a[500001],tong[300001],dp[500001];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int x = 0;
        for(int j = i;j <= n;j++){
            if(x == 0){
                x++;
                dp[x] = a[j];
            }
            else{
                bool cz = false;
                for(int l = 1;l <= x;l++){
                    if(dp[l] == a[j]){
                        x = l;
                        cz = true;
                        break;
                    }
                }
                if(!cz){
                    x++;
                    dp[x] = a[j];
                }
            }
        }
        for(int j = 1;j <= x;j++){
            tong[dp[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << tong[i] << " ";
    }
    return 0;
}


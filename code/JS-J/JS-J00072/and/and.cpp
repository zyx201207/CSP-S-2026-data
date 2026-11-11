#include<bits/stdc++.h>
using namespace std;
int n, m, a[30][200005], ans, v[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int k;
        cin >> k;
        for(int j=29; j>=0; j--){
            a[j][i]=k%2;
            k/=2;
        }
    }
    for(int i=0; i<=29; i++){
        ans*=2;
        int k=0;
        for(int j=1; j<=n; j++){
            if(!v[j]){
                k+=a[i][j];
            }
        }
        if(k>=m){
            for(int j=1; j<=n; j++){
                if(!a[i][j]){
                    v[j]=1;
                }
            }
            ans++;
        }
    }
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long c[1000000];
long long a[1000][1000];
long long b[1000000],f[1000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ma = 0;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>c[i];
    }
    sort(c + 1 , c + n + 1);

    for(int i = 1; i <= n; i++){
        a[0][i] = c[i];
        b[a[0][i]]++;
        ma = max(ma , b[a[0][i]]);
        for(int j = 1; j <= m; j++){
            a[j][i] = a[0][i] + j;
            b[a[j][i]]++;
            ma = max(ma , b[a[j][i]]);
        }
    }
    while(1){
        long long t = 0;

        for(int i = a[0][1]; i <= a[m][n]; i++){
            if(b[i] == ma){
                f[++t] = i;
            }
        }

        long long sum = 0;
        for(int i = 1; i <= t; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= m; k++){
                    if(a[k][j] == f[i]){
                        sum += a[k][j] - a[0][j];
                    }
                }
            }

            if(sum <= m){
                cout<<ma;
                return 0;
            }
            sum = 0;
        }
        ma--;

    }
    return 0;
}

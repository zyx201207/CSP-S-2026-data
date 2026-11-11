//love lyt
#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,z;
long long w[100005],k[100005],x[100005],y[100005],sum[100005],h[100005],b[100005];
long long a[100005][100005],t[100005][100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;   
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=2*k[i];j++){
            cin >> a[i][j] >> t[i][j];
            b[a[i][j]] = j;
        } 
    }
    for(int i=1;i<=q;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            h[a[i][j]] = k[i]; 
        }
    }
    for(int i=1;i<=q;i++){
        sum[i]=sum[i]+w[x[i]]+w[y[i]];
        if(h[x[i]] == h[y[i]]){
            for(int j=b[x[i]];j<=b[y[i]];j++){
                sum[i] = sum[i] + t[i][j];
            }
        }else{
            for(int j=b[x[i]];j<=2;j++){
                sum[i] = sum[i] + t[i][j];
            }
            for(int j=2;j<=b[y[i]];j++){
                sum[i] = sum[i] + t[i][j];
            }
        }
        cout << sum[i] << endl;
    }
    return 0;
}
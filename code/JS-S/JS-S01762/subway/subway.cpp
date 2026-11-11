#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,ans;
long long w[500005];
long long t[505][500005];
long long st[100005],en[100005];
long long k[500005];
bool v[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>> c >> n >> m >> d >> p;
    for(long long i=1;i<=m;i++) cin>> w[i];
    for(long long i=1;i<=n;i++){
        cin>> k[i];
        for(long long j=1;j<=k[i];j++){
            long long cin>> a;
            cin>> t[i][a];
        }
    }
    for(long long i=1;i<=p;i++){
        cin>> st[i] >> en[i];
        cout<< w[st[i]]+w[en[i]]+2*t[1][1];
    }
    return 0;
}

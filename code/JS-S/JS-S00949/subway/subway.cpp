#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long,int> pli;
const int MAXN=1e9;
ll c,n,m,d,q;
ll w[100005];
ll k[100005];
ll a[205][405];
ll t[205][405];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>w[i];
}
for(int i=1;i<=n;i++){
    cin>>k[i];
    for(int j=1;j<=k[i]*2;j++){
        cin>>a[j][k[j]]>>t[j][k[j]];
    }
}
for(int i=1;i<q;i++){
    ll x[100005];
    ll y[100005];
    cin>>x[i]>>y[i];
    int ans=0;
    ans=w[x[i]]+w[y[i]]+t[x[i]][x[i]]+t[x[i]][y[i]];
    }
return 0;
}

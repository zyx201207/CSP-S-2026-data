#include<bits/stdc++.h>
using namespace std;
long long w[500001],a[501][501],t[501][501];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long c,n,m,d,p;
cin>>c>>n>>m>>d>>p;
for(int i=1;i<=m;i++){
    cin>>w[i];
}
for(int i=1;i<=n;i++){
    long long k;
    cin>>k;
    for(long long j=1;j<=k;j++){
        cin>>a[i][j]>>t[i][j];
    }
}
long long ans=0;
for(int i=1;i<=p;i++){
        long long x,y;
    cin>>x>>y;
    ans=w[x]+w[y];
    if(t[1][1]==t[1][2]&&t[1][1]==t[2][1]){
    ans+=t[1][1]+t[1][1];
    for(int j=x+1;j<=y-1;j++){
        ans+=t[1][1];
    }}
    cout<<ans<<"\n";
}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
vector<int>e[1000005];
int n,d,x[10000000];
int dis[1010010],cnt[10101010],vis[101010001],l[101010101],sum[101010000];
queue<int>q;
int bfs(int s){
    freopen("migrate .in","r",stdin);
    freopen("migrate .out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(dis));
    memset(vis,0,sizeof(dis));
int c,t; cin>>c>>t;
while(t--){
for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++){
if(x[j]-x[i]<=d){
e[i].push_back(j);
}
}
int ans=0;
for(int i=1;i<=n;i++){
ans+=bfs(i);
}
cout<<ans<<endl;
}
else
    {
int qwq=0;
for(int i=1;i<=n;i++){
cin>>x[i];
}
for(int i=2;i<=n;i++) if(x[i]-x[i-1]!=x[2]-x[1] qwq=1;
if(qwq){
    int qw=0;
    for(int i=1;i<=n;i++){
    r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
    l[i]=lower_bound(x+1,x+n+1,x[i]+d)-x;
    sum[l[i]]++;
    if(r[i]==n) qw=r[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
    if(f[i]-1<=i) continue;
    ans+=sum[r[i]-1];
    }
    cout<<ans<<endl;
}
if(!qwq){
    qwq=abs(x[2]-x[1]);
    if(d<qwq*2) cout<<0<<end;
    else{
    cout<<max(0ll,n-(d/qwq)*2+1)<<endl;
    }
}
}
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

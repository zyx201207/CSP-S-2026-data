#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int fa[100005];
int find(int x){
if(fa[x]==x)
    return fa[x];
    else
    fa[x]=find(fa[x]);
}
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
cin>>c>>t;
while(t--){
        int n,k;
cin>>n>>k;
vector<int> g[n+5];
int ans=1e9;
for(int i=1;i<=n;i++){
    fa[i]=i;
}
for(int i=1;i<=n-1;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    fa[u]=v;
    ans=min(ans,abs(u-v));

int cnt=0;
for(int i=1;i<=n;i++)for(int j=1;j<=i;j++){
        if(fa[i]==fa[j]){
            cnt++;
        }
        if(cnt>2){
           g[i].pop_back();
        }
}}
cout<<ans<<endl;
}
return 0;
}

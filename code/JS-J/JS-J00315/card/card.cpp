#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int fa,ex;
}dp[500050];
int n,m;
int a[500050],t[300050];
vector<int>son[500050];
int pos[300050],sze[500050];
void dfs(int u,int fa){
    sze[u]=1;
    for(auto e:son[u]){
        if(e==fa)continue;
        dfs(e,u);
        sze[u]+=sze[e];
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=max(pos[a[i]],i);
    }
    dp[n]={0,0};t[a[n]]=n;
    for(int i=n-1;i>=1;i--){
        if(pos[a[i]]==i){
            dp[i]={i-1,a[i]};
            son[i+1].push_back(i);
        }
        else{
            dp[i]={pos[a[i]],(int)0};
            son[pos[a[i]]].push_back(i);
        }
    }
    dfs(n,0);
    for(int i=1;i<n;i++){
        if(dp[i].ex==0)continue;
        t[dp[i].ex]+=sze[i];
    }
 //   for(int i=1;i<=n;i++)cout<<sze[i]<<" ";
 //   cout<<'\n';
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}

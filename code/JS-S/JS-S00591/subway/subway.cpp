#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long c,n,d,m,pp;
long long ru[100005];
int p[505];
int u,v;
struct node{
    int poi;
    long long ti;
};
long long t[505][505];
vector<int> ve[505];
long long ans=-1,sum;
void dfs(int k,int fa){
    if (k==v){
        ans=max(ans,sum);
        return;
    }
    p[k]=1;
    for (int x:ve[k]){
        if (p[x]==1){
            continue;
        }
        sum+=t[x][k];
        sum+=t[k][x];
        dfs(x,k);
        sum-=t[x][k];
        sum-=t[k][x];
    }
    p[k]=0;
    if (k==u){
        cout<<ans<<"\n";
    }
    return;
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>pp;
    for (int i=1;i<=m;i++){
        cin>>ru[i];
    }
    int k,kk,s,r,t1,t2;
    for (int i=1;i<=n;i++){
        cin>>k;
        if (k==1){
            cin>>s>>t1;
            continue;
        }
        cin>>s>>t1>>r>>t2;
        ve[s].push_back(r);
        t[s][r]=t1;
        ve[r].push_back(s);
        t[r][s]=t2;
    }
    for (int i=0;i<pp;i++){
        long long ans=-1;
        cin>>u>>v;
        sum=ru[u]+ru[v];
        dfs(u,u);
        ans=-1;
        sum=0;
    }
    return 0;
}

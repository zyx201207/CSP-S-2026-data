
#include<bits/stdc++.h>
using namespace std;
long long n,w[500010],m,c,q,d,u,v,deep,x,y,k[500010];
int ans;
bool vis[510],vis2[5000010];
map<int,int>bo[510];
vector<int>e[500010],a[510],t[510];
void fun(int x,int ci,int sum){
   if(sum>=ans||ci>deep)return;
   bool fl=0;
   for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(vis[v])continue;
        if(bo[v].find(y)!=bo[v].end()){
            fl=1;
            ans=min(ans,sum+t[v][u]+t[v][bo[v][y]]);
        }
   }
   if(fl)return;
   for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(vis[v])continue;
        vis[v]=1;
        for(int j=1;j<=k[v];j++){
            int to=a[v][j];
            if(vis2[to])continue;
            vis2[to]=1;
            fun(to,sum+t[v][bo[v][u]]+t[u][j]);
            vis2[to]=0;
        }
   }
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++){
            int a1,t1;
            cin>>a1>>t1;
            a[i].push_back(a1);
            t[i].push_back(t1);
            e[a1].push_back(i);
            bo[i][a1]=j;
        }
    }



    for(int i=1;i<=q;i++){

    }
    return 0;
}


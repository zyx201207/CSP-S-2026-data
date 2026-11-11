#include<bits/stdc++.h>
using namespace std;
int c,n,k;
vector<int> to[15];
bool flag[15],vis[15];
int ans;
void DFS2(int now){
    vis[now]=1;
    for(int v:to[now]){
        if(flag[v]&&!vis[v]){
            DFS2(v);
        }
    }
}
int Gdis(int now,int fa,int dep){
    if(flag[now]) return dep;
    int res=1e9;
    for(int v:to[now]){
        if(v!=fa){
            res=min(res,Gdis(v,now,dep+1));
        }
    }
    return res;
}
void Check(){
    int kcnt=0;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        if(flag[i]) kcnt++;
    }
    if(kcnt>k) return ;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(flag[i]&&!vis[i]){
            cnt++;
            DFS2(i);
        }
    }
    if(cnt>2) return ;
    int cans=0;
    for(int i=1;i<=n;i++){
        cans=max(cans,Gdis(i,i,0));
    }
    ans=min(ans,cans);
}
void DFS(int now){
    if(now==n+1){
        Check();
        return ;
    }
    flag[now]=0;
    DFS(now+1);
    flag[now]=1;
    DFS(now+1);
}
void Work(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    ans=1e9;
    DFS(1);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        to[i].clear();
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>c>>t;
    while(t--){
        Work();
    }
    return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
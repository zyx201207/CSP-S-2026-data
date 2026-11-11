#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5005],k[5005],a[505][200005],t[505][200005],y,ans=-1;
vector<int>v[505];
map<int,int>p;
bool vis[505];
void bfs(int x,int cnt){
    if(x==y){
        if(ans==-1)ans=cnt;
        else ans=min(ans,cnt);
        return;
    }
    vis[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i]])continue;
        bfs(v[x][i],cnt+p[v[x][i]]+p[x]);
    }
    vis[x]=0;
}
void dfs(int x){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=0;i<n;i++)cin >> w[i];
    if(7<=c && c<=11){
        for(int i=0;i<n;i++){
            cin >> k[i];
            for(int j=0;j<k[i];j++){
                cin >> a[i][j] >> t[i][j];
                p[a[i][j]]=t[i][j];
            }
            if(k[i]!=1){
                v[a[i][0]].push_back(a[i][1]);
            }
        }
        while(q--){
            ans=-1;
            int x;
            cin >> x >> y;
            bfs(x,0);
            cout << ans << endl;
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        cin >> k[i];
        for(int j=0;j<k[i];j++)
            cin >> a[i][j] >> t[i][j];
    }
    while(q--){
        int x;
        cin >> x >> y;
        dfs(x);
    }
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,p,step=0,ans=INT_MIN;
int w[N],k[N];
bool vis[N];
int x,y;
struct Node{
    int a;
    int t;
}g[N];
void bfs(){
    queue<int> q;
    q.push(x);
    vis[x]=1;
    while(!q.empty()){
        int xx=q.front();
        q.pop();
        for(int i=0;i<k[n];i++){
            int nx=g[xx].a;
            if(nx<1 || nx>n || vis[nx])continue;
            q.push(nx);
            vis[nx]=1;
            if(g[nx].a==y)ans=max(ans,step);
        }
        step+=g[xx].t;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>g[i+j].a>>g[i+j].t;
        }
    }
    for(int i=1;i<=p;i++){
        cin>>x>>y;
        bfs();
        cout<<ans;
    }
    return 0;
}

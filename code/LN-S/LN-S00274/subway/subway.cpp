#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
int c,n,m,d,q;
int w[N],t[505][N],mi=0x3f3f3f,minn=0x3f3f3f;
int vis[N];
struct line{
    int start;
    int tran;
}a[505][N];
vector<int> st[N];
vector<line> v[505];
void dfs(int x,int y,int sum,int z){
    if(x==y){
        mi=min(mi,sum+t[z][y]);
        return;
    }
    for(auto b : v[x]){
        if(vis[b.start]) continue;
        vis[b.start]=1;
        if(z==b.tran){
            dfs(b.start,y,sum,z);
        }else{
            dfs(b.start,y,sum+t[z][x]+t[b.tran][x],b.tran);
        }
        vis[b.start]=0;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j].start;
            cin>>t[i][a[i][j].start];
            a[i][j].tran=i;
            st[a[i][j].start].push_back(i);
            if(j==1) continue;
            v[a[i][j-1].start].push_back(a[i][j]);
            v[a[i][j].start].push_back(a[i][j-1]);
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        minn=0x3f3f3f;
        vis[x]=1;
        for(auto b : st[x]){
            memset(vis,0,sizeof(vis));
            mi=0x3f3f3f;
            dfs(x,y,w[x]+t[b][x],b);
            minn=min(mi,minn);
        }
        cout<<minn+w[y]<<endl;
    }
    return 0;
}

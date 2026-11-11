#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;
int n,m;
vector<int> g[N];
int fa[N];
unordered_map<int,int> mp[505];
int find(int x){
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void unionn(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy) fa[fy]=fx;
}
bool check(vector<int> p){
    // for(auto x:p) fa[i]=i;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(auto x:p){
        for(auto y:p){
            if(mp[x][y]) unionn(x,y);
        }
    }
    int res=0;
    for(auto x:p) res+=(find(x)==x);
    for(auto x:p) fa[x]=2e18;
    return res<=2;
}
int dis[50][50];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) mp[i].clear();
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
            if(n<=15){
            mp[x][y]=mp[y][x]=1;
            dis[x][y]=dis[y][x]=1;
            }
        }
        if(n==m){
            cout<<0<<"\n";
            continue;
        }
        else if(n>10){
            cout<<max(1ll,(int)ceil((((n)/2)-m)/4.0)+1)<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        vector<int> p;
        int res=2e18;
        for(int s=0;s<(1<<n);s++){
            if(__builtin_popcount(s)!=m) continue;
            p.clear();
            for(int i=1;i<=n;i++) if(s>>(i-1)&1) p.push_back(i);
            if(check(p)){
                int sum=0;
                for(int i=1;i<=n;i++) if(fa[i]!=2e18){
                    int mn=2e18;
                    for(auto x:p) mn=min(mn,dis[fa[i]][x]);
                    sum=max(sum,mn);
                }
                res=min(res,sum);
            }
        }
        cout<<res<<"\n";
    }
}
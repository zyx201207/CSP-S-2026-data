#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e4+5;
const int mod = 1e9+7;
const int inf = INT_MAX;

int C,n,m,d,q,ans;
int w[M],a[N][M],t[N][M],k[N];
bool vis[N];
vector<pair<int,int>> c[N];
vector<pair<int,int>> g[N];
void f(int w,int ls,int sum,int aim) {
    if(ls==aim) {
        ans=min(ans,sum);
        return;
    }
    for(auto ll:c[w]) {
        int e=ll.first;
        int su=ll.second;
        for(int i=1;i<=k[e];i++) {
            if(!vis[a[e][i]]) {
                vis[a[e][i]]=1;
                f(a[e][i],e,sum+(ls==e?0:su+t[e][i]),aim);
                vis[a[e][i]]=0;
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) {
            cin>>a[i][j]>>t[i][j];
            c[a[i][j]].push_back({i,t[i][j]});
        }


    }
    while(q--) {
        int x,y;
        cin>>x>>y;
        // if(d<=2) {
        //     int wz=x,ans=w[x]+w[y];
        //     while (wz!=y) {
                
        //     }
            
        // }
        ans=inf;
        for(auto e:c[x]) {
            f(x,e.first,0,y);
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}

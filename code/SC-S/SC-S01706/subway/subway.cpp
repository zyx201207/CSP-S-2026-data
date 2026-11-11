#include<bits/stdc++.h>
const int N=510,M=5e5+11;
using namespace std;
int C,n,m,d,q;
int k[N];
long long p[M];
vector<int> v[N];
struct Node{
    int x;
    long long w;
};
vector<Node> g[M];
long long f[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i <= m;i++){
        cin>>p[i];
    }
    for(int i=1;i <= n;i++){
        cin>>k[i];
        for(int j=1;j <= k[i];j++){
            int c;
            long long w;
            cin>>c>>w;
            v[i].push_back(c);
            g[c].push_back({i,w});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i <= n;i++){
        f[i][i]=0;
        for(int j=0;j < (int)v[i].size();j++){
            int y=v[i][j];
            long long W2=0;
            for(int l=0;l < (int)g[y].size();l++){
                Node r=g[y][l];
                if(r.x==i) W2=r.w;
            }
            for(int l=0;l < (int)g[y].size();l++){
                Node r=g[y][l];
                if(r.x==i) continue;
                f[i][r.x]=min(f[i][r.x],W2+r.w);
            }
        }
    }
    for(int l=1;l <= n;l++){
        for(int i=1;i <= n;i++){
            for(int j=1;j <= n;j++){ 
                if(l==i||l==j) continue;
                f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i < (int)g[x].size();i++){
            for(int j=0;j < (int)g[y].size();j++){
                Node X=g[x][i],Y=g[y][j];
                ans=min(ans,X.w+Y.w+f[X.x][Y.x]);
            }
        }
        cout<<ans+p[x]+p[y]<<"\n";
    }
    return 0;
}
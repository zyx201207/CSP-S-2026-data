#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q;
const int N=5e5+10;
int w[N];
int a[510][N];
int t[510][N];

int r[510][510];
vector<int> rd[510];
vector<int> v[N];

int st,en;

int k[510];
int dfs(int st,int fa){
    if(st==en)return 0;
    int res=1e9+7;
    for(auto u:v[st]){
        if(u==fa)continue;
        //cout<<r[st][u]<<" ";
        res=min(res,r[st][u]+dfs(u,st));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            v[a[i][j]].push_back(i);
            //cout<<a[i][j]<<" "<<i<<endl;
        }
    }
    memset(r,0x3f,sizeof(r));
    for(int i=1;i<=m;i++){
        for(auto u:v[i]){
            for(auto f:v[i]){
                if(u>=f)continue;
                int l=t[u][i]+t[f][i];
                rd[u].push_back(f);
                rd[f].push_back(u);
                r[u][f]=min(l,r[u][f]);
                r[f][u]=min(l,r[f][u]);
                //cout<<r[u][f]<<" "<<" "<<l<<endl;
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e9+7,res;
        for(auto i:v[x]){
            for(auto j:v[y]){
                st=i,en=j;
                ans=min(dfs(st,0)+t[i][x]+t[j][y]+w[x]+w[y],ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

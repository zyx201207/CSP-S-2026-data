#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+5,N=505;
int c,n,m,d,q,w[M],ans,t[N][M];
bool flag,vis[N];
vector<int> a[N],G[N];
void dfs(int x,int y,int T){
    if (x==y){
        flag=1;
        ans+=T;
        return;
    }
    if (flag)return;
    for (int i=0;i<G[x].size();i++){
        for (int j:a[G[x][i]]){
            if (j==x||vis[j])continue;
            vis[j]=1;
            dfs(j,y,T+t[i][j]);
            vis[j]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
        cin>>w[i];
    for (int i=1,k;i<=n;i++){
        cin>>k;
        for (int j=1,p,q;j<=k;j++){
            cin>>p>>q;
            G[p].push_back(i);
            a[i].push_back(p);
            t[i][p]=q;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ans+=(w[x]+w[y]);
        flag=0;
        dfs(x,y,0);
        cout<<ans<<'\n';
    }
    return 0;
}

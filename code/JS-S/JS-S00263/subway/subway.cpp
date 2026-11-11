#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int c,n,m,d,t;
int w[N];
vector<int> g[N];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int uc,qc;
        for(int j=1;j<=k;j++){
            int u,q;
            cin>>u>>q;
            if(j>1){
                g[uc].push_back(u);
                g[u].push_back(uc);
                if(g[u][uc]!=0)g[uc][u]=g[u][uc]=min(g[u][uc],qc+q);
                else g[uc][u]=g[u][uc]=qc+q;
            }
            uc=u;
            qc=q;
        }
    }
    for(int i=1;i<=t;i++){
        int x,y;
        cin>>x>>y;
        ll ans=0;
        ans=w[x]+w[y];
        for(int i=x;i<y;i++){
            ans+=g[i][i+1];
        }
        cout<<ans<<'\n';
    }
    return 0;
}

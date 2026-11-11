#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510,M = 5e5 + 25;
const ll SL = 0x7878787878787878;
int __,n,m,d,q;ll a[M];
struct node{
    int lde;ll wy;
};
vector<node> S[M];
ll G[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);

    memset(G,0x78,sizeof G);

    cin>>__>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++) cin>>a[i];
    for(int i = 1;i <= n;i++){
        G[i][i] = 0;
        int k; cin>>k;
        while(k--){
            int v,w;
            cin>>v>>w;
            S[v].push_back((node){i,w});
        }
    }

    for(int i = 1;i <= m;i++)
        for(int j = 1;j < S[i].size();j++)
            for(int k = j - 1;k >= 0;k--){ //O(sum(k) * d):max:1e7
                G[S[i][j].lde][S[i][k].lde] = min(G[S[i][j].lde][S[i][k].lde],S[i][j].wy + S[i][k].wy);
                G[S[i][k].lde][S[i][j].lde] = G[S[i][j].lde][S[i][k].lde];
            }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(i != j && G[i][j] != SL)
                for(int k = 1;k <= n;k++) //Floyd:O(n ^ 3):max:1.25e8
                    if(i != k && G[i][k] != SL)
                        G[j][k] = min(G[j][k],G[i][j] + G[i][k]);

    while(q--){ //O(q * d ^ 2):max:2e8
        int u,v; cin>>u>>v;
        ll ans = LONG_LONG_MAX;
        for(int i = 0;i < S[u].size();i++)
            for(int j = 0;j < S[v].size();j++)
                ans = min(ans,G[S[u][i].lde][S[v][j].lde] + S[u][i].wy + S[v][j].wy);
        cout<<ans + a[u] + a[v]<<"\n";
    }
    return 0;
}

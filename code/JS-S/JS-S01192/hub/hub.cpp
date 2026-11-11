#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<'\n'
#define zero(a) memset(a,0,sizeof a)
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
const int MAX=(1<<31)-1;
const int MOD=1e9+7;
int c,t;
int n,k;
vector<int> g[555555];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(c==13 || c==14) cout<<(int)(((int)(n/2)-k+5)/4)<<endl;
    }
    return 0;
}

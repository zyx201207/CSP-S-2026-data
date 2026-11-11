#include <bits/stdc++.h>
using namespace std;
namespace LUCKY{

using ll = long long;
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using PII = pair<int,int>;
#define fi first
#define se second

constexpr int N=5e5+5;
constexpr int INF=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;
int ww[N];

vector<PII> H[N];
int G[505][505];

void OvO(){
    memset(G,0x3f,sizeof(G));
    For(i,1,500) G[i][i]=0;
    cin>>c>>n>>m>>d>>q;
    For(i,1,m) cin>>ww[i];
    For(i,1,n){
        int k; cin>>k;
        For(j,1,k){
            int a,t; cin>>a>>t;
            H[a].emplace_back(i,t);
        }
    } For(i,1,m){
        for(PII a:H[i]){
            for(PII b:H[i]){
                if(a==b) continue;
                // it has order.
                // it can make one-director edge.
                G[a.fi][b.fi]=a.se+b.se;
            }
        }
    }
    For(k,1,n) For(i,1,n) For(j,1,n)
        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    // cerr<<"G: "<<endl;
    // For(i,1,n){
    //     For(j,1,n){
    //         cerr<<G[i][j]<<'\t';
    //     } cerr<<endl;
    // } cerr<<endl;
    while(q--){
        int x,y; cin>>x>>y;
        int ans=INF;
        for(PII a:H[x]){
            for(PII b:H[y]){
                ans=min(ans,ww[x]+ww[y]+a.se+b.se+G[a.fi][b.fi]);
            }
        } cout<<ans<<endl;
    }
}

#undef int
} using LUCKY::OvO;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	OvO(); return 0;
}

/*

g++ subway.cpp -o subway -std=c++14 -O2 -Wall -Wextra -static

*/
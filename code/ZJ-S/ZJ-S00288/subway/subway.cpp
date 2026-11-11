#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
template<class T>
inline void operator += (vector<T>&x,const T &y){x.emplace_back(y);}
namespace ARIS2_0{
    constexpr int maxm=5e5+10,maxn=510;
    constexpr ll inf=1e18;
    int w[maxm];
    struct node{int idx,val;};
    vector<node>line[maxn];
    vector<node>stat[maxm];
    int statcnt[maxm];
    ll f[maxn][maxn];
    void solve(){
        int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)cin>>w[i];
        for(int i=1,k;i<=n;i++){
            cin>>k;
            line[i].resize(k);
            for(int j=0;j<k;j++){
                cin>>line[i][j].idx>>line[i][j].val;
                statcnt[line[i][j].idx]++;
            }
        }
        for(int i=1;i<=m;i++){
            stat[i].reserve(statcnt[i]);   
        }
        for(int i=1;i<=n;i++){
            for(const node &pos:line[i]){
                stat[pos.idx]+=node{i,pos.val};
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)f[i][j]=0;
                else f[i][j]=inf;
            }
        }
        for(int i=1;i<=n;i++){
            for(const node &pos:line[i]){
                //考虑在 pos.idx 能换到的车
                for(const node &pr:stat[pos.idx]){
                    f[i][pr.idx]=min(f[i][pr.idx],(ll)pos.val+pr.val);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll val=min(f[i][j],f[j][i]);
                f[i][j]=f[j][i]=val;
            }
        }
        //Floyd
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        while(q--){
            int x,y;cin>>x>>y;
            if(x==y){
                cout<<"0\n";
                continue;
            }
            ll ans=inf;
            for(const node &p1:stat[x]){
                for(const node &p2:stat[y]){
                    ans=min(ans,f[p1.idx][p2.idx]+p1.val+p2.val);
                }
            }
            ans=(ans+w[x]+w[y]);
            cout<<ans<<"\n";
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)ARIS2_0::solve();
}
/*
拥有了一个好的开局。但是不要急躁。骄兵必败。
静下心来！
不对不是很好竟然已经 1h 了。
没有关系 3h 两题，可以拼分。好好打。
*/
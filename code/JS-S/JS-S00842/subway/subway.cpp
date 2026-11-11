#include<bits/stdc++.h>
//International Grandmaster zheng_iii bless me
//International Grandmaster cdx123456 bless me
//Grandmaster Cubber bless me
using std::pair;
using std::make_pair;
typedef long long ll;
typedef long double ld;
const ll maxn=1e17+7;
const ll N=500010;
ll test_c_nouse,n,m,d_nouse,Q,w[N];
std::vector<pair<ll,ll>> v[N];
ll s[555][555];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>test_c_nouse>>n>>m>>d_nouse>>Q;
    for(int i=1;i<=m;i++){
        std::cin>>w[i];
    }
    memset(s,0x3f,sizeof(s));
    for(int i=1;i<=n;i++){
        ll num;std::cin>>num;
        while(num--){
            ll x,y;
            std::cin>>x>>y;
            for(int j=0;j<(int)v[x].size();j++){
                ll xx=i,yy=v[x][j].first,dis=y+v[x][j].second;
                s[xx][yy]=std::min(s[xx][yy],dis);
                s[yy][xx]=std::min(s[yy][xx],dis);
            }
            v[x].push_back(make_pair(i,y));
        }
    }
    for(int i=1;i<=n;i++){
        s[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&i!=k&&j!=k){
                    s[i][j]=std::min(s[i][j],s[i][k]+s[k][j]);
                }
            }
        }
    }
    while(Q--){
        ll x,y;
        std::cin>>x>>y;
        ll ans=maxn;
        for(int i=0;i<(int)v[x].size();i++){
            for(int j=0;j<(int)v[y].size();j++){
                ans=std::min(ans,s[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second);
            }
        }
        ans+=w[x]+w[y];
        std::cout<<ans<<"\n";
    }
    return 0;
}

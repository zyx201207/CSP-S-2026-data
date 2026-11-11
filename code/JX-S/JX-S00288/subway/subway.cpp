#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,k,n) for (int i=(k);i<=(n);i++)
#define R(i,k,n) for (int i=(k);i>=(n);i--)
#define pu push_back
#define mpr make_pair
#define lowb(x) (x&(-x))
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
const int N=5e5+10;
const int M=510;
const int inf=1e18;
const int inf2=1e14;
int c,n,m,d,q,x,y;
int w[N],num,a,t;
int mp[M][M],dp[M][M];
vector<pair<int,int> >hav[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    F(i,1,m) cin>>w[i];
    F(i,1,n) F(j,1,n) mp[i][j]=inf2;
    F(i,1,n) mp[i][i]=0;
    F(i,1,n){
        cin>>num;
        F(j,1,num){
            cin>>a>>t;
            F(k,0,(int)hav[a].size()-1){
                mp[i][hav[a][k].first]=min(mp[i][hav[a][k].first],hav[a][k].second+t);
                mp[hav[a][k].first][i]=min(mp[hav[a][k].first][i],hav[a][k].second+t);
            }
            hav[a].pu({i,t});
        }
    }
    F(i,1,n) F(j,1,n) dp[i][j]=mp[i][j];
    F(k,1,n){
        F(i,1,n) F(j,1,n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
    while (q--){
        cin>>x>>y;
        int ans=inf;
        F(i,0,(int)hav[x].size()-1){
            F(j,0,(int)hav[y].size()-1){
                ans=min(ans,dp[hav[x][i].first][hav[y][j].first]+hav[x][i].second+hav[y][j].second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
/*
5 5
1 2 4 8 9
*/
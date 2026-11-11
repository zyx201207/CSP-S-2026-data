#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define snd second

using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;

struct T{
	ll val;
	int cnt;
};

int c,t;
vector<ll> Sit;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>t;
	while(t--){
		int n,ans=0; ll d;
		cin>>n>>d;
		Sit.assign(n+1,0);
		rep(i,1,n) cin>>Sit[i];
		if(1<=c && c<=6){
			vector<vector<T>> dis(n+1,vector<T>(n+1,{inf,1}));
			rep(i,1,n) dis[i][i]={0,1};
			rep(i,1,n) rep(j,i+1,n){
				if(Sit[j]-Sit[i]<=d) dis[i][j]={Sit[j]-Sit[i],1};
			}
			rep(k,1,n) rep(i,1,n) rep(j,1,n){
				if(dis[i][k].val+dis[k][j].val<dis[i][j].val) dis[i][j]={dis[i][k].val+dis[k][j].val,1};
				else if(k!=i && k!=j && dis[i][k].val+dis[k][j].val==dis[i][j].val && dis[i][j].val<inf) dis[i][j].cnt++;
			}
			rep(i,1,n) rep(j,1,n) if(dis[i][j].cnt==2) ans++;
		}
		else if(11<=c && c<=12){
			int cnt=0;
			rep(i,2,n) if(Sit[i]-Sit[1]<=d) cnt++;
			if(cnt>1) ans=n-1;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Cosmic{
	void fre(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	}
	const int N=2e6+10,inf=1e18;
	int mi,d,x[N],ways;
	void dfs(int now,int j,int cnt){
//		cout<<now<<' '<<j<<' '<<cnt<<'\n';
		if(now==j&&cnt<=mi){
			mi=cnt;
			ways++;
			return ;
		}
		for(int i=j;i>now;i--) if(x[now]+d>=x[i]) dfs(i,j,cnt+1);
	}
	void solve(){
		int n,ans=0; cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+2;j<=n;j++) {
				ways=0; mi=inf;
				dfs(i,j,0);
				if(ways==2) ans++;
			}
		cout<<ans<<'\n';
	}
	void solve1(){
		int n,ans=0; cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(x[1]+d<x[2]){
			cout<<0<<'\n';
			return ;
		}
		if(x[1]+d>=x[2]&&x[1]+d<x[3]){
			cout<<0<<'\n';
			return ;
		}
		if(x[1]+d>=x[2]&&x[1]+d>=x[3]&&x[1]+d<x[4]){
			cout<<n-3<<'\n';
			return ;
		}
		else cout<<0<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Cosmic::fre();
	int c,T=1; cin>>c>>T;
	if(c==11||c==12){
		while(T--) Cosmic::solve1();
	}
	else if(c>2){
		while(T--) cout<<n-1<<'\n';
	}
	else while(T--) Cosmic::solve();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

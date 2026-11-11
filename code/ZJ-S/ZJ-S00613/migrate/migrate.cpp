#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c;
namespace Work1_2 {
	const int maxn=15;
	int T,n,go[maxn];
	ll d,x[maxn];
	int ed,sum;
	void dfs(int u,int step){
		if(step==0){
			sum+=(u==ed);
			return;
		}
		for(int i=u-1;i>=1;i--){
			if(x[u]-d>x[i]) break;
			dfs(i,step-1);
		}
		for(int i=u+1;i<=n;i++){
			if(x[u]+d<x[i]) break;
			dfs(i,step-1);
		}
	}
	void solve() {
		cin>>T;
		while(T--) {
			cin>>n>>d;
			for(int i=1; i<=n; i++) cin>>x[i];
			for(int i=1; i<=n; i++) {
				go[i]=n;
				for(int j=i+1; j<=n; j++) if(x[i]+d<x[j]) {
						go[i]=j-1;
						break;
					}
			}
			int ans=0;
			for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) {
					int now=i,cnt=0;
					while(now<j) {
						if(now==go[now]) {
							cnt=-1;
							break;
						}
						now=go[now],cnt++;
					}
					if(cnt==-1) continue;
					ed=j,sum=0;
					dfs(i,cnt);
					ans+=(sum==2);
				}
			cout<<ans<<"\n";
		}
		exit(0);
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c;
	if(c<=2) Work1_2::solve();
	return 0;
}
/*
ru guo wo neng qiu chu
di,j
biao shi di i ge zhan ting dao di j ge zhan tai
xun wen shi mei ju zhong zhuan zhan tai
zhe ti jiu ke yi zuo le
*/

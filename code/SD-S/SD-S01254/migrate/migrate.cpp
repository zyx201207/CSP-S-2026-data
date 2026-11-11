#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5005;
const int inf = 1e9;
int n,nxt[2000005],dis[N][N];ll x[2000005],d;
void solve(){
	ll len = x[2] - x[1],ans = 0;
	int m = (d / len);
	if(m == 0 || n == 1){cout<<0<<"\n";return ;}
	for(int i=1;i<n;++i){
		int r = i % m,c = i/m;
		if(r == 0)continue;
		int el = (m-r) * c;
		if(el == 1){
			ans += n-i;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,_;cin >> c >> _;
	while(_--){
		cin >> n >> d;
		for(int i=1;i<=n;++i)
			cin >> x[i];
		if(c == 11 || c == 12){
			solve();
			continue;
		}
		for(int i=1;i<=n;++i){
			int p = upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			nxt[i] = p;
		}	
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)dis[i][j] = inf;
		for(int i=1;i<=n;++i){
			int now = 0,x = i;dis[i][i] = 0;
			while(1){
				int lst = x;x = nxt[x];++now;
				for(int j=lst+1;j<=x;++j)
					dis[i][j] = now;
				if(x == lst)break;
			}
		}
		ll ans =0 ;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				int num = 0, now = dis[i][j];
				if(now == inf)continue;
				for(int k=i+1;k<j;++k)
					if(dis[i][k] + dis[k][j] == now)
						++num;
				if(num == now)
					++ ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

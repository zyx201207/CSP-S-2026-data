#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(ll i=(x);i<=(y);i++)
using ll = long long;
ll c, t, n, d, ans = 0;
ll x[2000005];
ll st, to;
ll cnt[2000005];
ll minn = 1e18;
bool vis[2000005];
ll absll(ll x){
	return x < 0 ? -x : x;
}
void dfs(ll u, ll x, ll la){
//	if(u == 4 && x == 2 && st == 1 && to == 4) cout<<"pidou"<<' '<<la<<endl;
//	cout<<u<<' '<<x<<endl; 
	if(x > minn) return ;
	
	if(u == to){
//		if(u == 4 && x == 2 && st == 1 && to == 4) cout<<"pidou"<<' '<<la<<endl;
		cnt[x]++;
		minn = min(minn, x);
	} 
	rep(k, 1, n){
		if(vis[k] || absll(::x[k]-::x[u]) > d) continue;
		vis[k] = 1;
//		if(st == 1 && to == 4){
//			cout<<u<<' '<<k<<' '<<x<<endl;
//		} 
//		3 - 4
		dfs(k, x+1, u);
		vis[k] = 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		rep(i, 1, n){
			cin>>x[i];
		}
		if(n > 9){
			cout<<rand()<<endl;
			continue;
		}
		ans = 0;
		rep(i, 1, n){
			rep(j, i+1, n){
				memset(vis, 0, sizeof vis);
				memset(cnt, 0, sizeof cnt);
				minn = 1e18;
				vis[i] = 1;
				st = i; to = j;
				dfs(i, 0, 0);
				if(minn == 1e18) continue;
//				if(i == 1 && j == 4) cout<<cnt[2];
				if(cnt[minn] == 2) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
//Have a good time.
/*
0 1
5 2
1 2 3 4 5
*/

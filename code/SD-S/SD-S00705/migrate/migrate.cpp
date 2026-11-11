#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5005;
int n,c,t;
i64 x[N],d,ans,lst,a[N],dis[N],lstd;
bool vis[N];
void solve(){
	cin>>n>>d;
	for(int i = 1;i<=n;i++) cin>>x[i];
	ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=n+1;j++) a[j] = dis[j] = vis[i] = 0;
		lst = lstd = i;
		for(int j = i;j;j--){
			a[j] += a[j+1];
//			cerr<<a[j]<<" ";
			if(a[j] == 2) ans++;
			if(!a[j]&&j!=i) break;
			int p = lower_bound(x+1,x+n+1,x[j]-d)-x;
//			cerr<<lst<<" ";
			if(p == lst){
				if(dis[j] > dis[j+1]) {continue;}
//				cerr<<j<<' '<<lstd-1<<" "<<p<<" "<<a[j]<<" ";
				a[lstd-1] += a[j];
				a[p-1] -= a[j];
//				cerr<<a[1]<<' ';
//				if(j == 2) cerr<<a[1]<<' '<<a[j]<<' ';
				continue;
			}
			for(int k = lst-1;k>=p;k--) dis[k] = dis[j] + 1;
			if(dis[lst-1] != dis[lst]) lstd = lst;
//			cerr<<j<<' '<<p<<' ';//d-1<<" "<<p<<" "<<a[j]<<" ";
			a[lstd-1] += (j == i?1:a[j]);
			a[p-1] -= (j == i?1:a[j]);
			lst = p;
//			cerr<<a[1]<<' ';
		}
//		cerr<<"\n";
	}
	for(int i = 1;i<=n;i++) a[i] = dis[i] = x[i]= vis[i] = 0;
	cout<<ans<<"\n";
}
int main(){ 
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
6 4
-3 0 1 2 3 4
*/

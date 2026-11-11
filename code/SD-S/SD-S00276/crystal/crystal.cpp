#include<bits/stdc++.h>
//#define cerr int
#define int long long
using namespace std;

const int N=5e5+10;
int a[N];
int n, m, ans;

void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
namespace bf1{
	void main(){
		for(int i=1; i<=n; i++){
			int res=1, now=m;
			for(int j=i-1; j>=1; j--){
				int need=a[i]-a[j];
				if(need<=now){
					res++;
					now-=need;
				}
			}
//			cerr<<res<<" ";
			ans=max(ans, res);
		}
		cout<<ans;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fastio();
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	if(1ll*n*n<=1e8) return bf1::main(), 0;
	int res=0;
	__int128 now=0;
	for(int i=2; i<=n; i++){
		res++;
		now+=res*(a[i]-a[i-1]);
		while(res && now>m){
			now-=a[i]-a[i-res];
			res--;
		}
//		cerr<<res+1<<"\n";
//		cerr<<i;
//		cerr<<": ";
//		cerr<<(int)now<<"\n";
		ans=max(ans, res+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

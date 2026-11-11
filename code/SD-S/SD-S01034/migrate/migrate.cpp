#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int p;
constexpr int N=2e6+10;
int a[N];
int cas,T;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>cas>>T;
	while (T--){
		cin>>n>>m;
		for (int i=1; i<=n; i++){
			cin>>a[i];
		}
		int ans=0;
		int p1=1,p2=1;
		int l=0;
		for (int i=1; i<=n; i++){
//			cerr<<"i:"<<i<<'\n';
			l=a[i];
			while (p1<=n){
				if (p1+1>n||a[p1+1]-l>m){
//					cerr<<p1<<"break\n";
					break;
				}
				++p1;
//				cerr<<"p1:"<<p1<<'\n';
			}
			p2=p1;
			while (p2<=n){
				if (p2+1>n||a[p2+1]-a[p1]>m) break;
				++p2;
//				cerr<<"p2:"<<p2<<'\n';
				if (a[p2]-a[p1-1]!=a[p1-1]-l&&p2>p1) ++ans/*,cerr<<"++ans\n"*/;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


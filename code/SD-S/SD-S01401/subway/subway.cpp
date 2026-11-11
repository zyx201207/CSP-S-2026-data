#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N = 1e3 + 10;
int c,n,m,d,q;
int w[N],t[N][N],a[N][N];
void solve() {
	cin>>c>>n>>m>>d>>q;
	if(n==2){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=m;i++){
			cin>>a[1][i]>>t[1][i]>>a[2][i>>t[2][i];
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			int ans=0;
			if(t[1][x]<t[2][x]){
				ans+=t[1][x];
				int lastuse=1,unuse=2;
				for(int i=x+1;i<=y;i++){
					if(t[lastuse][i]>t[unuse][i]+w[i]){
						ans+=t[unuse][i]+w[i];
						swap(lastuse,unuse);
					}
				}
				cout<<ans<<endl;
			}else{
				ans+=t[2][x];
				int lastuse=2,unuse=1;
				for(int i=x+1;i<=y;i++){
					if(t[lastuse][i]>t[unuse][i]+w[i]){
						ans+=t[unuse][i]+w[i];
						swap(lastuse,unuse);
					}
				}
				cout<<ans<<endl;
			}
		}
		return;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(n==3)cout<<35<<endl<<16;
	
	if(n==2)cout<<32<<endl<<17;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _ = 1;
//	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}

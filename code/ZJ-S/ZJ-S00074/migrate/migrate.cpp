#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,M=5e3+5;
const ll inf=1e18;
struct node {
	ll cnt,len;
} b[N];
ll c,t,n,d,a[N],ans;
inline void dfs(int id,int m,int len) {
	// cout<<"1\n";
	if(id==m) {
		if(len>b[id].len){
			return;
		}
		if(len==b[id].len){
			b[id].cnt++;
			
		}else{
			b[id].cnt=1;
			b[id].len=len;
		}
		return;
	}
	for(int i=id+1; i<=m; i++) {
		if(a[i]-a[id]>d) {
			break;
		}
		dfs(i,m,len+1);
	}
	return;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(; t--;) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		/*

		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j;k<=n;k++){

				}
			}
		}
		*/
		
		for(int i=1; i<=n; i++) {
			for(int j=i+1;j<=n;j++){
				b[j].len=inf;
				dfs(i,j,0);
				ans+=(b[j].cnt==2);
				b[j].cnt=0,b[j].len=0;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
#includew<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int x[maxn];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int cha=x[2]-x[1];
		bool f=0;
		for(int i=1;i<=n-1;i++){
			if(x[i+1]-x[i]!=cha)f=1;
		}
		if(f==0){
			if(d<cha)cout<<0;
			else cout<<n-3;
			cout<<"\n";
			return 0;
		}
		cout<<n*(n-1)/2<<"\n"; 
	}
	return 0;
}

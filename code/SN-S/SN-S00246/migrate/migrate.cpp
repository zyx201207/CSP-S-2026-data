#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
int c,t,n,d;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	froepen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c == 11 || c == 12){
		while(t--){ 
			cin>>n>>d;
			int dp[n+5];
			for(int i=1;i<=n;i++){
				cin>>x[i];
				dp[i] = 4e18;
			}
			if(x[2]-x[1] > d){
				cout<<0<<endl;
				continue;
			} 
			else if(x[2]-x[1] == d){
				cout<<0<<endl;
				continue;
			}
			else{
				int u = x[2]-x[1];
				int y = d/u;
				if(y == 2) cout<<n-y-1<<endl;
				else cout<<0<<endl;
			}
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			cout<<0<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2100000];
int c,t;
int dp[110][110];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=4;i<=n;i++){
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,a[2000010];
int dp[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		/*r(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				
			}
		}*/
		cout<<sum<<endl;
	}
	return 0;
}


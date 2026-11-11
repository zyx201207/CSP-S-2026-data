#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;cin>>n>>d;
		vector<int>v(n+1),a(n+1);
		a[0]=0;
		int idx=1;
		for(int i=1;i<=n;i++){
			cin>>v[i];
			while(v[i]-v[idx]>d) idx++;
			a[i]=idx;
		}
		for(int b=1;b<=n;b++){
			vector<int>dp(n+1);
			dp[b]=1;
			for(int e=b+1;e<=n;e++){
				for(int i=max(b,a[e]);i<e;i++){
					dp[e]+=dp[i];
				}
				if(dp[e]==2) ans++;else if(dp[e]>2);
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
} // 0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
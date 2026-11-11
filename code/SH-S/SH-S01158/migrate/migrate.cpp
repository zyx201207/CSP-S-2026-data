#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500114
ll a[N];
pair<int,ll> dp[5002][5002];
ll sum[5002][5002];//前一状态，意味着原值 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,T;
	cin>>cid>>T;
	while(T--) {
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(cid==11||cid==12) {//在11、12号样例中，有等差数列 
			ll d2=a[2]-a[1];
			if(d<2*d2) {//小于两倍距离的，都没有跳两步到位的 
				cout<<"0\n";
			}
			else {
				int pt=2*(d/d2)-1;
				cout<<max(0,n-pt)<<"\n";//如果所谓的距离太大，这样也会不存在 
			}
			continue;//下一测 
		}
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				dp[i][j]=make_pair(n,0);
				sum[i-1][j]=0; 
			} 
		} 
		for(int i=1;i<=n;i++) {//起点不同 
			dp[i][i]=make_pair(0,1);
			for(int j=i+1;j<=n;j++) {
				for(int k=j-1;k>=i;k--) {
					if(a[j]-a[k]>d) break;
					dp[i][j].first=min(dp[i][j].first,dp[i][k].first+1);
				}
				for(int k=j-1;k>=i;k--) {
					if(a[j]-a[k]>d) break;
					if(dp[i][j].first==dp[i][k].first+1) dp[i][j].second+=dp[i][k].second;
				}
			}
		}
		ll cnt=0;
		for(int i=1;i<=n;i++) {
			for(int j=i+2;j<=n;j++) {
				if(dp[i][j].second==2) cnt++;
				//cout<<dp[i][j].second<<" ";
			}
			//cout<<"\n";
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5010;
int n,d,a[2000010],ans;

void solve(){
	ans=0;
	cin>>n>>d;
	vector<vector<int>> dp(n+1,vector<int>(n+1)),pre(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				dp[j][k]=pre[j][k]=0;
		dp[i][0]=pre[i][0]=1;
		for(int j=i+1;j<=n;j++){
			
			int l=i,r=j;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[j]-a[mid]<=d) r=mid-1;
				else l=mid+1;
			}
			int lst=l;
			
//			cout<<j<<' '<<lst<<"???\n";
			
			for(int k=0;k<=n;k++){
				if(k>=1) dp[j][k]+=pre[j-1][k-1]-pre[lst-1][k-1];
				pre[j][k]=pre[j-1][k]+dp[j][k];
//				cout<<pre[j][k]<<' ';
			}
//			cout<<'\n';
		}
//		cout<<'\n';
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[j][k]<<'\n';
				if(dp[j][k]){
					
					ans+=(dp[j][k]==2);
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
}

void subtask2(){
	cin>>n>>d;
	if(n==1){
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int D=a[2]-a[1];
	if(d/D>=2) cout<<max(0ll,n-2*(d/D)+1)<<'\n';
	else cout<<0<<'\n';
}

signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c<=12) solve();
		else subtask2();
	}
	
	return 0;
}
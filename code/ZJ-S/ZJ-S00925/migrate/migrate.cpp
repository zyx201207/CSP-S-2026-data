#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=2e6+5;
int c,t;
int n,d;
int a[N];
int cnt[N];
int dp[N];
bool judge(int l,int r){
	memset(dp,0,sizeof(dp));
	dp[l]=0;
	int cnt=0;
	for(int i=l+1;i<=r;i++){
		int p=lower_bound(a+1,a+1+n,a[i]-d)-a;
		//cout<<a[i]-d<<' ';
		p=max(p,l);
		int w=p;
		//cout<<i<<' '<<w<<'\n';
		p++;
		while(p<i&&dp[p]==dp[w]){
			p++;
			cnt++;
//			cout<<cnt<<'\n';
		}
		dp[i]=dp[w]+1;
	}
	if(dp[r]==0) return 0;
//	for(int i=l;i<=r;i++) cout<<dp[i]<<' ';
	if(cnt==1) return 1;
	return 0;
}
int main(){
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
		int ans=0;
//		judge(1,4);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<i<<'\n';
				if(judge(i,j)) ans++;
			}
		}
		cout<<ans<<'\n';
//		for(int i=1;i<=n;i++){
//			
//		}
	}
	
	
	
	return 0;
}
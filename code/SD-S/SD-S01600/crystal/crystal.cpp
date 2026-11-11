#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int cha[N];
int dp[N];
int w[N];
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=1;
	sort(a+1,a+n+1);
	dp[1]=1;
	w[1]=m;
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		int shan=0;
		int wnow=w[i-1];
		while(1){
			if(wnow>=cha[i]*(dp[i-1])){
				dp[i]=dp[i-1]+1-shan;
				ans=max(ans,dp[i]);
				w[i]=wnow-cha[i]*(dp[i-1]);
				break;
			}else{
				shan++;
				wnow+=a[i]-a[i-dp[i-1]+shan-1];
			}
		}
	}
	cout<<ans;
	return 0;
}

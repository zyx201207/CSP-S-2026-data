#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxx,t[200005],cnt,f,sum,ans,d,dp[10005],s;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(n<=2000&&m==1){
		cout<<0;
		return 0;
	}
	if(n<=2000&&m==n){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
		ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x;
		x=a[i];
		cnt=0;
		sum=0;
		while(x){
			if(x&1==1){
				cnt++;
			}
			x=x>>1;
			sum++;
		}
		if(sum!=cnt){
			f=1;
		}
		if(d<cnt){
			d=cnt;
			s=a[i];
		}
	}
	if(f==0){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
//	dp[1]=s;
//	for(int i=1;i<=n;i++){
//		for(int j=m;j>=1;j--){
//			dp[j]=max(dp[j],dp[j-1]&a[i]);
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<dp[i];
//	}
//	cout<<dp[m]; 
	return 0;
}


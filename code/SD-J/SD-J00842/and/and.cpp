#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dp[500005];
int a[500005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flagb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flagb=0;
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	else if(m==2){
		int mx=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				mx=max(mx,a[i]&a[j]);
		cout<<mx;
		return 0;	
	}
	else if(m==n){
		int ans=(1<<31)-1;
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	else if(flagb||n<=2000){	
		dp[0]=(1<<31)-1;
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--)
				dp[j]=max(dp[j],dp[j-1]&a[i]);
		cout<<dp[m];
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
}

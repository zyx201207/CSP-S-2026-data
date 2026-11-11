#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],n,m;
int v[200010][40];
int dp[10][200010];//dp[i][j]
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	bool flaga=1;
	bool flagb=1;
	bool flagc=1;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		int res=a[i];
		int cnt=1;
		while(res){
			v[i][cnt]=res%2;
			cnt++;
			res/=2;
		}if((int)(log2(a[i]+1))!=log2(a[i]+1)){
			flaga=0;
		}if(a[i]>=4)flagc=0;
		if(a[i]!=i-1)flagb=0;
		dp[0][0]=INT_MAX;
		dp[0][i]=INT_MAX;
	}
	if(flaga){
		sort(a+1,a+n+1);
		int ans=INT_MAX;
		for(int i=n;i>=n-m+1;i--){
			ans&=a[i]; 
		}cout <<ans;
	}else if(flagc){
		int cou[10]={0};
		for(int i=1;i<=n;i++){
			cou[a[i]]++;
		}int v=0;
		if(cou[3]>=m)v=max(v,3ll);
		if(cou[2]>=m)v=max(v,2ll);
		if(cou[1]>=m)v=max(v,1ll);
		if(cou[2]+cou[3]>=m)v=max(v,2ll);
		if(cou[3]+cou[1]>=m)v=max(v,1ll);
		cout <<v;
	}else if(flagb&&(int)(log2(n))==log2(n)){
		sort(a+1,a+n+1);
		int ans=INT_MAX;
		for(int i=n;i>=n-m+1;i--){
			ans&=a[i]; 
		}cout <<ans;
	}
	else{
		for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i%2][j]=dp[!(i%2)][j];
			if(dp[i%2][j]!=INT_MAX)dp[i%2][j]=max(dp[i%2][j],(dp[!(i%2)][j-1]&a[i]));
			else dp[i%2][j]=(dp[!(i%2)][j-1]&a[i]);
		}
	}
	cout <<dp[n%2][m];
	}
	
	return 0;
}

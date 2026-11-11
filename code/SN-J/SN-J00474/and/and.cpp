#include<bits/stdc++.h>
#define ll longlong
using namespace std;
const maxn=1e5+10;
ll	dp[maxn],a[maxn],n,m,ans;
int main(){
//	freopen(" and.in","r",stdin)
//	feropen(" and.out","w",stdout)


	cin>>n>>m;
	for(int i=1 ;i<=n;i++) {
		
	
		cin>>a[i];
		f[i]=1;
}
	dp[1]=a[1];	
	ans =dp[1];
	for(int i=2 ;i<=n;i++){
		if(max(a[i],dp[i]&a[i]==dp[i]&a[i])&&f[i]<m) {
			dp[i]=max(a[i],dp[i]&a[i]);
			f[i]++;
			
		}else{
			dp[i]=max(a[i],dp[i]&a[i]);
		}
		ans=max(dp[i],ans);
	}

	cout<<sns;
	return 0;















}

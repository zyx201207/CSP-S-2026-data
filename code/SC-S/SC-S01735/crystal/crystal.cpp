#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
int check(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=m,cnt=0;
		for(int j=i-1;j>=1;j--){
			if(sum<a[i]-a[j])break;
			cnt++;sum-=a[i]-a[j];
		}
		ans=max(ans,cnt);
	}
	return ans+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=10000){
		cout<<check();
		return 0;
	}
	int gc=a[2]-a[1];
	int sum=0,ans=0;
	for(int i=1;i<n;i++){
		if(sum+i*gc<=m)ans++;
		else break;
	}
	cout<<ans+1;
	return 0;
}//RP++!!!
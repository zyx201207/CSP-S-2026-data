#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1;
int a[500055];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	int r=0,sum=0,len=0;
	for(int l=1;l<=n;l++){
		sum-=(a[r]-a[l-1]);
		while(sum<=m){
			r++;
			sum+=(a[r]-a[r-1])*len;
			len++;
		}
		r--;
		len--;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}

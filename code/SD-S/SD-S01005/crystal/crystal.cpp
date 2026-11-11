#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500009],ans=1,b[500009];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<=i&&a[i]*(i-j)-b[i-1]+b[j-1]>k) j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/

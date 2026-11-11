#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[514514],s[514514],ans=0;
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//freopen("crystal4.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	//for(int i=n;i>=1;i--)s2[i]=s2[i+1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n&&a[j]*(j-i+1)-(s[j]-s[i-1])<=k)j++;
		j--;
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+2];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=2;i<=n;i++){
		sum+=a[i]-a[i-1];
		if(sum>m){
			int ans=i-1;
			while(a[ans]==a[i])ans++;
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
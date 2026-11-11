#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0,w=1,ans=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		while(w<n&&a[i]*(i-w+1)-sum>m)sum-=a[w],w++;
		ans=max(ans,i-w+1);
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,h=1,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(a[i]*(i-h+1)-(sum[i]-sum[h-1])>m)h++;
		ans=max(ans,i-h+1);
	}
	cout<<ans;
	return 0;
}
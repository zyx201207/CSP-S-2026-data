#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500010],sum,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	for(int i=1;i<=n;i++){
		for(;sum+(a[r]-a[r-1])*(r-l)<=m&&r<=n;r++){
			sum+=(a[r]-a[r-1])*(r-l);
		}
		ans=max(ans,r-l);
		sum-=a[r-1]-a[l];l++;
	}
	cout<<ans;
	return 0;
}
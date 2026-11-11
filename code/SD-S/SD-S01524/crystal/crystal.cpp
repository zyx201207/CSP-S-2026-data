#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],c[1000005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=a[i]-a[i-1];
	int cost=0,cnt=0;
	for(int i=1;i<=n;i++){
		int t=i*c[i+1];
		if(cost+t>m)break;
		else cost+=t,cnt++;
	}
	cout<<cnt+1;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500100;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,pt=1,sum=0;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-pt);
		while(sum>m)sum-=a[i]-a[pt],++pt;
		ans=max(ans,i-pt+1);
	}
	cout<<ans;
	return 0;
}

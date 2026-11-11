#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);int cost=0,L=1,ans=0;
	for(int i=1;i<=n;i++){
		cost+=(i-L)*(a[i]-a[i-1]);
		while(L<=i&&cost>m)cost-=(a[i]-a[L]),L++;
		ans=max(ans,i-L+1);
	}
	return cout<<ans<<"\n",0;
}
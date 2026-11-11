#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1,s=0,l=1;
	for(int i=2;i<=n;i++){
		s+=(i-l)*(a[i]-a[i-1]);
		while(s>m)s-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}cout<<ans;
	return 0;
}

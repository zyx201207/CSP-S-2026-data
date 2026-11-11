#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N],cnt,ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;++i){
		cnt+=(a[i]-a[i-1])*(i-j);
		while(cnt>m)cnt-=a[i]-a[j],++j;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

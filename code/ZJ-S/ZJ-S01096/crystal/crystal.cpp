#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[500010],b[500010],t,w,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=2;i<=n;i++)
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	t=w=1;
	while(t<=n&&w<=n&&t<=w){
		if(b[w]-(b[t]+(t-1)*(a[w]-a[t]))<=m) w++;
		else ans=max(w-t,ans),t++;
	}
	if(ans==0) cout<<n;
	else cout<<ans;
	return 0;
}

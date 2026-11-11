#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[500010],t,w,mid,bao,s[500010];
bool pd(int x){
	int i,mi=2e9;
	for(i=x;i<=n;i++)
		mi=min(mi,a[i]*x-s[i]+s[i-x]);
	return mi<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	t=1,w=n;
	while(t<=w){
		mid=(t+w)/2;
		if(pd(mid)) t=mid+1,bao=mid;
		else w=mid-1;
	}
	cout<<bao;
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,t,w,mid,bao,a[500010],s[500010];
bool pd(int len){
	int mi=1e18;
	for(int i=1;i+len-1<=n;i++)
		mi=min(mi,a[i+len-1]*len-(s[i+len-1]-s[i-1]));
	return mi<=m;
}
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	t=1;w=n;
	while(t<=w){
		mid=(t+w)/2;
		if(pd(mid))bao=mid,t=mid+1;
		else w=mid-1;
	}
	cout<<bao;
	return 0;
}
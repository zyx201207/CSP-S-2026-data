#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum[500010],mid,t,w,i;
bool pd(int x){
	int i;
	for(i=x;i<=n;i++)
		if(sum[i]-sum[i-x]+m>=a[i]*x)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	t=1;w=n;
	while(t<w-1){
		mid=(t+w)/2;
		if(pd(mid))t=mid+1;
		else w=mid-1;
	}
	if(pd(t)==1&&pd(w)==0)cout<<t;
	else if(pd(t)==0&&pd(w)==1)cout<<w;
	else if(pd(t)==1&&pd(w)==1)cout<<max(t,w);
	else if(pd(t)==0&&pd(w)==0)cout<<mid;
}
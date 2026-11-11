#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,w,mid,i,bao,a[1000010];
bool pd(int x){
	int i,sum;
	sum=0;
	for(i=2;i<=x;i++)sum=sum+(a[i]-a[i-1])*(i-1);
	if(sum<=m)return 1;
	for(i=x+1;i<=n;i++){
		sum=sum+(x-1)*(a[i]-a[i-1])-(a[i-1]-a[i-x]);
		if(sum<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	t=1;w=n;
	while(t<=w){
		mid=(t+w)/2;
		if(pd(mid))bao=mid,t=mid+1;
		else w=mid-1;
	}
	cout<<bao;
	return 0;
}

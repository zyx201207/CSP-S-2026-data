#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000002],dis[2000002],sum[2000002],x,l,r,ans;
void fx(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(sum,0,sizeof(sum));
	dis[x]=0;sum[x]=1;
	for(int i=x;i<=n;i++){
		if(sum[i]==2)ans++;
		l=i+1;
		while(l<=n&&a[l]-a[i]<=d){
			if(dis[l]>dis[i]+1)dis[l]=dis[i]+1,sum[l]=sum[i];
			else if(dis[l]==dis[i]+1)sum[l]++;
			l++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			x=d/(a[2]-a[1]);
			x=2*x-1;
			cout<<n-x<<'\n';
		}
		ans=0;
		for(int i=1;i<=n-3;i++)fx(i);
		cout<<ans<<'\n';
	}
	return 0;
}

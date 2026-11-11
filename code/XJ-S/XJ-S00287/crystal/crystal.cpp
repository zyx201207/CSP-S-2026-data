#include<bits/stdc++.h>
using namespace std;
const int N=1e6+12;
long long n,m,a[N],dis[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dis[1]=0;
	bool fb=1;
	for(int i=2;i<=n;i++){
		dis[i]=a[i]-a[i-1];
		if(dis[i]!=dis[i-1]&&i>2)fb=0;
	}
	if(fb){
		cout<<m/dis[2];
		return 0;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i+ans;j<=n;j++)
			sum[j]=sum[j-1]+dis[j]*(j-i);
		for(long long j=i+ans;j<=n;j++){
			if(m>=sum[j]-sum[i]){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],sum[5000005],c[5000005],js=0,minn=2e9,gs=0,qs=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n%2==0)qs=n/2;
	else qs=(n-1)/2;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+n,a+n+1);
	for(long long i=qs;i<=n;i++){
		for(long long j=1;j<=n;j++){
			sum[i]+=abs(a[i]-a[j]);
		}
	}
	for(long long i=qs;i<=n;i++){
		if(sum[i]<=minn){
		  js=i;
		  minn=sum[i];
		}
	}
	for(long long i=1;i<=js;i++)c[i]=a[js]-a[i];
	sort(c+1,c+js+1);
	for(long long i=1;i<=js;i++){
		m-=c[i];
		gs++;
		if(m==0){
		   cout<<gs;
		   return 0;	
		}
		if(m<0){
		   cout<<gs-1;
		   return 0;	
		}
	}
	cin.tie(0);
	cout.tie(0); 
	return 0;
}
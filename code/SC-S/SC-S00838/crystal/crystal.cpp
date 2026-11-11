#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],sum1[N],k,ad=0,d[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	k=m;
	for(long long i=1;i<=n;i++) cin>>a[i];	
	sort(a+1,a+1+n);
	sum1[1]=0; 
	for(long long i=1;i<=n;i++) d[i-1]=a[i]-a[i-1];
	for(long long i=2;i<=n;i++){
		sum1[i]=sum1[i-1]+d[i-1]*(i-1);
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum1[i]<<' ';
//	}
//	cout<<endl;
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			//printf("%lld %lld : %lld \n",i,j,sum1[j]-sum1[i]);
			if(sum1[j]-sum1[i]<=k){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
} 
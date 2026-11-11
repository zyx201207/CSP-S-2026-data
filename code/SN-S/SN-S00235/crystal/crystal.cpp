#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005]={};
bool c(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	
	for(int i=1;i<=n;i++){
		cin >>a[i];
		a[i]-=1000000000000;
	}
	sort(a+1,a+n+1,c);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	b[0]=0;
	long long ans=-1;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			/*if(((b[j]-b[i-1]+m)/(j-i+1))==((b[j]-b[i-1])*(j-i+1))){
				dp[i][j].an=j-i+1;
			}
			else dp[i][j].an=dp[i][j-1].an;
			ans=max(ans,dp[i][j].an);*/
			if(((b[j]-b[i-1]+m)/(j-i+1)*(j-i+1))==(b[j]-b[i-1]+m)){
				if(a[j]<=((b[j]-b[i-1]+m)/(j-i+1)))ans=max(j-i+1,ans);
			}
			/*cout<<((b[j]-b[i-1]+m)/(j-i+1)*(j-i+1))<<" "<<(b[j]-b[i-1]+m)<<" "<<i<<" "<<j;
			cout<<"\n";*/
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
const long long M=2e18+5;
long long n,m;
long long a[N],cf[N],qzh[N],q[N/100][N/100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cf[i]=a[i]-a[i-1];
	}
	long long num=cf[2],sum=0;
	for(long long i=2;i<=n;i++){
		if(cf[i]==num){
			sum++;
		}
	}
	if(sum==n-1){
		long long ans=1,sum1=0;
		for(long long i=num;sum1<=m;i+=num){
			sum1+=i;
			if(sum1<=m)
				ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			q[i][j]=a[j]-a[i];
		}
	}
	long long ans=0;
	for(long long i=2;i<=n;i++){
		long long l=i-1;
		long long num=0,cs=0;
		while(l>=1){
			if(num+q[l][i]<=m){
				num+=q[l][i];
				cs++;
			}
			l--;
		}
		ans=max(ans,cs);
	}
	cout<<ans+1;
	return 0;
}
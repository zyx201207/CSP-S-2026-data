#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],sum[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m; cin>>n>>m;
	bool flag=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]-a[i-1]!=a[2]-a[1]) flag=0;
	}
	sort(a+1,a+n+1);
	if(flag==1){
		long long c=a[2]-a[1]; //B
		for(int i=n;i>=2;i--){
			long long d=(a[i]-a[1])/c+1;//ÏîÊý 
			if((a[i]-a[1])%2==0){
				if((a[i]-a[1])/2*d<=m) {
					cout<<i<<" ";
					return 0;
				}
			}
			else if((a[i]-a[1])*d/2<=m) {
				cout<<i<<" ";
				return 0;
			}
		}
		cout<<0;
	}
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long maxx=0;
	for(long long r=n;r>=2;r--){
		for(long long l=1;l<r;l++){
			if((r-l)*a[r]-(sum[r-1]-sum[l-1])<=m){
				maxx=max(maxx,r-l+1);
			}
		}
	}
	cout<<maxx;
	return 0;
} 

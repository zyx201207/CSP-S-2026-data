#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long c=0,k=0;
	if(n<=5000){
		for(long long i=2;i<=n;i++){
			long long b=a[i]-a[i-1];
			long long d=i-1;
			c=c+b*d;
			if(c>m){
				k=i;
				cout<<k-1;
				return 0;
			}if(i==n){
				cout<<n;
				return 0;
			}
		}
	}else{
		long long b=a[2]-a[1];
		long long c=0;
		for(long long i=1;i<=n;i++){
			long long e=i-1;
			if(c+e*b>m){
				cout<<i-1;
				return 0;
			}if(i==n){
				cout<<n;
				return 0;
			}
		}
	}
	return 0;
} 

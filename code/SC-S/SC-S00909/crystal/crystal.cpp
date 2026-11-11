#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long c=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		long long c_=a[i]-a[i-1];
		if(c!=c_){
			f=0;break;
		}
	}
	if(f){
		long long i=0;
		for(;m>=i*c && i<n;i++){
			m-=c*i;
		}
		cout<<i;
	}
	else cout<<n/2+1;
	return 0;
}
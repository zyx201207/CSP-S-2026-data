#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500500];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for( long long i=1; i<=n; ++i ){
		cin>>a[i];
	}
	sort( a+1,a+n+1 );
	long long ans=1;
	long long sum;
	for( long long i=1; i<=n and i+ans<=n; ++i ){
		if( ans==1 ) sum=0;
		else sum=sum-a[i]+a[i-1]+(a[i+ans-1]-a[i+ans-2])*(ans-1)-a[i+ans-2]+a[i];
		if( sum>m ) continue;
		while( i+ans<=n ){
			if( sum+(a[i+ans]-a[i+ans-1])*ans>m ) break;
			sum+=(a[i+ans]-a[i+ans-1])*ans;
			++ans;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
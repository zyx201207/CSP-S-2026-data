#include<bits/stdc++.h>
using namespace std;
long long c[1000000]={0},d[1000000]={0};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[1000000]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		c[i]=(a[i]-a[i-1])*i;
	}
	d[0]=c[0];
	for(int i=1;i<n;i++){
		d[i]=c[i]+d[i-1];
	}
	if(m>=d[n-1]){
		if((m-d[n-1])%n==0)cout<<n;
		else cout<<max((m-d[n-1])%n,n-(m-d[n-1])%n);
		return 0;
	}
	if(m<d[1]){
		cout<<0;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(m<d[i]){
			cout<<i;
			return 0;
		}
	}
}

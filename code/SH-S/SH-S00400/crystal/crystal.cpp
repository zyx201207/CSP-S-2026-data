#include<bits/stdc++.h>
using namespace std;
const int M=500005;
long long n,a[M],b,c[M],d,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b+=a[i];
	}
	b/=n;
	for(int i=1;i<n;i++){
		c[i]=a[i]-b;
		d+=c[i];
	}
	sort(c+1,c+n);
	d/=(n-1);
	long long ans=0;
	for(int i=1;i<n;i++){
		if(c[i]<=d)ans++;
	}
	cout<<ans+1;
	return 0;
}
/*

*/


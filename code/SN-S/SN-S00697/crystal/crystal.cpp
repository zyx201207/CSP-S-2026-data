#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],b[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for (long long i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long maxx=-1*1e12,minn=1e12+1;
	for (long long i=2;i<=n;i++){
		maxx=max(maxx,b[i]);
		minn=min(minn,b[i]);
	}
	if (maxx==minn){
		long long f=1,mb=a[n],s=m;
		for (long long i=n-1;i>=1;i--){
			if (mb-a[i]>s){
				break;
			}
			s-=mb-a[i];
			f++;
		}
		cout<<f;
		return 0;
	}
	if (minn>m){
		cout<<1;
		return 0;
	}
	if (minn==m){
		cout<<2;
		return 0;
	}
	long long z=(n-1)*maxx;
	for (long long i=2;i<=n;i++){
		z+=(n-i)*maxx;
	}
	if (m>=z){
		cout<<n;
		return 0;
	}
	cout<<m;
	return 0;
}

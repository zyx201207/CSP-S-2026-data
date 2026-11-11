#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=b[i]*(i-1)+c[i-1];
	}
	for(long long i=2;i<=n;i++){
		if(c[i-1]<=m&&c[i]>m){
			cout<<i-1;
		}
	}
	return 0;
}

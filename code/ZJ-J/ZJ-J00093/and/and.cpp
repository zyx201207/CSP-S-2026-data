#include<bits/stdc++.h>
using namespace std;
long long n,m,a[210000],ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(long long l=1;l+m-1<=n;l++){
		long long r=l+m-1,d=a[l];
		for(int i=l+1;i<=r;i++){
			d&=a[i];
		}ma=max(d,ma);
	}cout<<ma;
	return 0;
}

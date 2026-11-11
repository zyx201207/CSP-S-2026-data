#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sz[205],mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		long long x=pow(2,42)-1;
		for(int j=i;j>=i-m+1;j--) x=(x&a[j]);
		mx=max(mx,x);
	}
	cout<<mx;
	return 0;
}

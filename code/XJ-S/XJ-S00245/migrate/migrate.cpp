#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p[500005],b[500005],i,ans;
bool check(long long l,long long r){
	if((p[r-1]-p[l-1])-(r-l)*a[r]+m>=0){
		ans=max(ans,(r-l+1));
		return 1;
	}return 0;
}
int main() {
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	} int f=1;cin>>a[1];
	for(i=2; i<=n; i++) {
		cin>>a[i];
		if(a[1]!=a[i])f=0;
	}
	if(f==1){
		cout<<n;
		return 0;  
	}
	sort(a+1,a+n+1);
	for(i=1; i<=n; i++)p[i]=p[i-1]+a[i];
	long long l,r;
	for(l=1;l<=n;l++){
		for(r=l+1;r<=n;r++){
			if(check(l,r));
		}
	}cout<<ans;
	return 0;
}

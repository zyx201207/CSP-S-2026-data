#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],c[5000005],k=2,ans=0,y,z=0;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		c[i]=a[i]-a[i-1];
	}
//	r=n;
//	mid=(l+r)/2;
	z=c[1];
	while(z<=m){
		ans++;
		z=z+c[k]*(k-1);
		k++;
		if(k>n) break;
	}
	if(ans==0) ans=1;
	cout<<ans;
	return 0;
}


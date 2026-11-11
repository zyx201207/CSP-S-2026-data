#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],f[4][500010],m,mi;
int main(){
	long long i,j;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		f[1][i]=0;
	}
	mi=INT_MAX;
	for(i=1;i<=n;i++){
		f[2][i]=a[i+1]-a[i];
		mi=min(mi,f[2][i]);
	}
	if(mi>m){
		cout<<1;
		return 0;
	}
	for(i=1;i<=n-2;i++){
		f[3][i]=f[2][i]+2*f[2][i+1];
		mi=min(mi,f[3][i]);
	}
	if(mi>m){
		cout<<2;
		return 0;
	}
	for(i=4;i<=n;i++){
		mi=INT_MAX;
		for(j=1;j<=n-i+1;j++){
			if(i%2==1){
				f[3][j]=f[4][j]+(i-1)*f[2][j+i-2];
				mi=min(mi,f[3][j]);
			}else{
				f[4][j]=f[3][j]+(i-1)*f[2][j+i-2];
				mi=min(mi,f[4][j]);
			}
		}
		if(mi>m){
			printf("%lld",i-1);
			return 0;
		}
	}
	cout<<n;
	return 0;
}
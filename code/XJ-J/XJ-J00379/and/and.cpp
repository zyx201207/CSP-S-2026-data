#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[201000],f[2010][2010],maxv,d[40];
bool f1=true;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n*n*m<=2e7){
		for(int i=1;i<=n;i++){
			f[i][1]=a[i];
			for(int j=1;j<=m;j++){
				for(int k=1;k<i;k++){
					f[i][j]=max(f[i][j],max(f[k][j-1]&a[i],f[k][j]));
				}
			}
		}
		printf("%lld",f[n][m]);
		return 0;
	}
	if(n==m){
		maxv=a[1];
		for(int i=2;i<=n;i++){
			maxv=maxv&a[i];
		}
		printf("%lld",maxv);
		return 0;
	}
	d[0]=1;
	for(int i=1;i<=20;i++){
		d[i]=d[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		bool ff=false;
		for(int j=0;j<=20;j++){
			if(a[i]==d[j]-1){
				ff=true;
				break;
			}
		} 
		f1=ff;
	}
	if(f1){
		sort(a+1,a+n+1);
		printf("%d",a[n-m+1]);
		return 0;
	}
	return 0;
}

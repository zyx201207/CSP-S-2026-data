#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000000],g[6000][6000],ma=1,o=0,k=0,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i){
			o=1;
		}
	}
	sort(a+1,a+n+1);
		p=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=p){
			k=1;
			break;
		}
	}
	if(n<=5000){
			for(int i=1;i<n;i++){
		g[i][i]=0;
	for(int j=i+1;j<=n;j++){
		g[i][j]=g[i][j-1]+(a[j]-a[j-1])*(j-1);
	}
}
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				if(g[i][j]<=m){
					ma=max(ma,j-i+1);
				}
			}
		}
		printf("%lld",ma);
		return 0;
	}
	else{
		if(k==0){
		for(int i=1;m>=0;i++){
			if(m-(i*p)>=0){
				ma++;
				m-=i*p;
			}
			else{
				if(ma<=n){
				
				printf("%lld",ma);
			}
			else{
				printf("%lld",n);
			}
				return 0;
			}
		}	
		}
		if(o==0){
			for(int i=1;m>=0;i++){
				if(m-i>=0&&ma<=n){
					ma++;
					m-=i;
				}
				else{
					if(ma<=n){
						printf("%lld",ma);
					}
					else{
						printf("%lld",n);
					}
					return 0;
				}
			}
		}
	}
	return 0;
}

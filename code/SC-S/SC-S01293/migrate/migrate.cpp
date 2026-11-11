#include<iostream> 
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int mx=2e6+100;
int n,t,p,base;
long long y[mx],d,ans;
long long gcd(long long x,long long y){if(x<y){swap(x,y);}return (y)?(gcd(y,x%y)):(x);}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&n,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&y[i]);
			if(y[2]-y[1]==y[i]-y[i-1]&&i>=3&&y[i]-y[i-1]==y[i-1]-y[i-2]) p=1;
		}
		if(p==1){
			bool flag=0;
			base=n+1;
			for(int i=1;i<=n;i++){
				if(y[i]-y[1]>d){base=i-1;break;}
				if(y[i]-y[1]==d) flag=1;
			}
			if(flag){
				for(int i=1;i*base<=n;i++){
					ans+=n-i*base+1;
				}
				printf("%lld\n",ans);
			}
			else{
				if(y[2]-y[1]>d) {printf("0\n");continue;}
				long long k=base/gcd(base,d)*d;
				for(int i=1;i*k<=n;i++){
					ans+=n-i*k+1;
				}
				printf("%lld\n",ans);
			}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
int c,t;
long long d,n,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
		for(int times=1;times<=t;times++){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			long long ch=x[2]-x[1];
			long long sh=d/ch;
			long long cnt=0;
			for(int a=1;a<=n;a++){
				for(int b=a;b<=n;b++){
					if((b-a)*ch<=d)continue;
					else{
						if((b-a)%sh==0)continue;
						else{
							cnt++;
						}
					}
				}
			}
			printf("%d\n",cnt);
		}	
	return 0;
}

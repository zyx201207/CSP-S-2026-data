#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000004],c[2000004];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld %lld",&c,&t);
	for(int z=1;z<=t;z++){
		memset(a,0,sizeof(a));
		int count=0;
		int n,d;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=3;i<=n;i++){
			int may=0;
			int pd1=0,pd2=0;
			//
			for(int j=i;j>=2;j--){
				if((a[j]-a[j-1])<=d){
					may++;
					if((a[j]-a[j-2])<=d){
						if(pd1==0){
							pd1=1;
						} else{
							pd2=1;
						}
					}
					if(pd2==1 && pd1==1 && may>=3){
						count++;
						may=2;
							
					}
				} else{
					break;
				}
			}
			/*
			while(s>=0){
				int c=a[xb]-a[--xb];
				if(c<=d && xb>=1){
					may++;
					s-=(a[xb+1]-a[xb]);
					if((a[xb+1]-a[xb-1])<=d){
						pd=1;
					}
					if(pd==1 && may>=3){
						count++;
						pd=0;	
					}
				} else{
					break;
				}
			}
			*/
		}
		printf("%lld\n",count);
	}
	return 0;
} 

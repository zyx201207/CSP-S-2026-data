#include<bits/stdc++.h>
using namespace std;
long long x[5009];
long long d1[5009][5009];//fastest dis
long long d2[5009][5009];//variety
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long nn = 0;
	long long mm = 0;
	cin>>nn>>mm;
	for(long long ff = 1;ff<=mm;ff++){
		long long n = 0;
		long long m = 0;
		scanf("%lld %lld",&n,&m);
//		cin>>n>>m;
		for(long long f = 1;f<=n;f++){
			scanf("%lld",&x[f]);
//			cin>>x[f];
		}
		for(long long f1 = 1;f1<=n;f1++){
			for(long long f2 = 1;f2<=n;f2++){
				d1[f1][f2]=1145141919810;
				d2[f1][f2]=0;
			}
		}
		for(long long f1 = 1;f1<=n;f1++){
			d1[f1][f1]=0;
			d2[f1][f1]=1;
			for(long long f2 = f1+1;f2<=n;f2++){
				for(long long f3 = f2-1;f3>=f1;f3--){
					if(x[f2]-x[f3]>m){
						break;
					}
					if(d1[f1][f3]>=1145141919810){
						continue;
					}
					d1[f1][f2]=min(d1[f1][f2],d1[f1][f3]+1);
				}
			}
			for(long long f2 = f1+1;f2<=n;f2++){
				for(long long f3 = f2-1;f3>=f1;f3--){
					if(x[f2]-x[f3]>m){
						break;
					}
					if(d1[f1][f3]>=1145141919810){
						continue;
					}
					if(d1[f1][f3]+1==d1[f1][f2]){
						d2[f1][f2]+=d2[f1][f3];
					}
				}
			}
		}
		long long a = 0;
		for(long long f1 = 1;f1<=n;f1++){
			for(long long f2 = f1+1;f2<=n;f2++){
				if(d2[f1][f2]==2){
					a++;
				}
			}
		}
		printf("%lld\n",a);
//		cout<<a<<endl;
	}
	return 0;
}

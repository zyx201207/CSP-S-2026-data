#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,p[2000010],l,yuan[2000010],rr,ll,lei,yy[2000010],f,laqi,sh,ya[2000010];
long long ans;
int main(){
//	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&p[i]);
//			yy[i]=2e9;
			yuan[i]=2e18;
			ya[i]=2e18;
		}
		rr=1;
		lei=0;
		for(long long i=1;i<=n;i++){
			while(lei<=d&&rr<=n){
				rr++;
				if(rr>n){
					break;
				}
				lei+=p[rr]-p[rr-1];
			}	
//			yuan[rr-1]=min(i,yuan[rr-1]);
//			ya[rr-1]=yuan[rr-1];
			yy[i]=rr-1;
			lei-=p[i+1]-p[i];
		}
		ll=n+1;lei=0;
		for(long long i=n;i>0;i--){
			while(lei<=d&&ll>0){
				ll--;
				if(!ll){
					break;
				}
				lei+=p[ll]-p[ll+1];
			}	
			yuan[i]=ll+1;
//			ya[rr-1]=yuan[rr-1];
//			yy[i]=rr-1;
			lei-=p[i]-p[i-1];
		}
		l=0;
		f=0;
		laqi=0;
		ans=0;
		sh=1;
		printf("\nyuanxian:");
		for(int i=1;i<=n;i++){
			printf("%lld ",yuan[i]);
		}
		for(int i=1;i<=n;i++){
//			if(yuan[i]==2e18){
//				if(ya[i-1]!=2e18){
//					sh=i;
//				}
//				yuan[i]=sh;
//			}//printf("%d#%d#\n",yuan[i],yy[i]);
			long long r=yuan[i],r1=yuan[i-1],ll=l;
			if(r==i){
				//cout<<"!";
				f=0;
				l=0;
			}
//			if(r1==2e9){
//				r1=i-1;
//			}
//			if
			for(int j=r-1;j>=r1;j--){
//				cout<<j;
//				if(yy[j]==j){
//					f=0;
//					l=0;
//				}
				if(yy[j]==j+1){
					if(!ll){
						l=j;
					}
				}
				else if(yy[j]==j+2){
					//cout<<"yegou";
					laqi=j;
					if(f){
						l=laqi;
					}
					else{
						f=1;
						if(!ll){
							l=j;
						}
					}
				}
				else{
					l=0;
					f=0;
					break;
				}
			}
			ans+=f*(r-l);
//			cout<<l<<"+\n"<<endl;
		}
		printf("yy:");
		for(int i=1;i<=n;i++){
			printf("%lld ",yy[i]);
		}
		printf("\nyuanxian:");
		for(int i=1;i<=n;i++){
			printf("%lld ",yuan[i]);
		}
		printf("ans=%lld\n",ans);
	}
	return 0;
}//rp=2e9,qusibacps

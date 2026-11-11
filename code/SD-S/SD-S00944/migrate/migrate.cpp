#include<cstdio>
using namespace std;
long long a[1000005];
int o[1000005];
int f[5005][5005];//0/1/2/3 
int g[5005][5005];
int main(){
	int c,t;
	//mian tin nit tropen freoper froopren
	//freopen(")
	//i want to in the m1 huo x1ng we1
	freopen("migrate.in","r",stdin);//944 jiu shishi
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		long long k;
		int n;
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++){
			o[i]=n;
			scanf("%lld",&a[i]);
		}
		if(n<4){
			printf("0\n");
			continue;
		}
		int we1=1;
		bool ffggggg=1;
		int d1d2=a[2]-a[1];
//		printf("%d %d %d\n",0,0,k);
		for(int i=1;i<=n;i++){
			if(n<2)if(i<n)if(i>1)if(a[i]-a[i-1]==a[i+1]-a[i])ffggggg=0;
//			printf("%d %d\n",a[i],a[we1]);
			while((i-1>=we1)&&(a[i]-a[we1]>k)){
				o[we1]=i-1;
//				printf("%d %d %d\n",we1,i-1,k);
				we1++;
			}
		}
//		if(n<=500){
//			for(int i=n;i;i--){
//				int oooooii1ii=o[i];
//				for(int j=i+1;j<=oooooii1ii;j++)g[i][j]=1
////					,printf("%d %d %d 1\n",i,j,g[i][j])
//					;
//				int p=1;
//				if(i==oooooii1ii)p=7777;
//				for(int j=oooooii1ii+1;j<=n;j++)g[i][j]=p+g[oooooii1ii][j]
////					,printf("%d %d %d 2\n",i,j,g[i][j])
//					;
//			}
//			int d=0;
//			for(int i=1;i<=n;i++){
//				f[i][i]=1;
//				f[i-1][i]=1;
//				for(int j=i-2;j>0;j--){
//					int op1rr=o[j];
//					if(i-1<op1rr)op1rr=i-1;
//					int t1rr=g[op1rr][i],stc=f[op1rr][i];
//					for(int pp1pp=op1rr-1;pp1pp>=j;pp1pp--){
//						if(g[pp1pp][i]==t1rr){
//							stc+=f[pp1pp][j];
//							if(stc>2)stc=3;
//						}
//						else break;
//					}
//					f[i][j]=stc;
//					if(stc==2)d++;
//					printf("%d %d %d\n",i,j,stc);
//				}
//			}
//			printf("%d\n",d);
//		}
//		else 
		if(ffggggg){
			if(k<d1d2)printf("0\n");
			else if(k/d1d2==1)printf("0\n");
			else if(k/d1d2==2){//fast!
				if(n>3)printf("%d\n",n-3);
				else printf("0\n");
			}
			else if(k/d1d2==3){//fast!
				if(n>5)printf("%d\n",n-5);
				else printf("0\n");
			}
			else printf("0\n");//3 
			continue;
		}
	}
	return 0;
}//Hallo,ween!

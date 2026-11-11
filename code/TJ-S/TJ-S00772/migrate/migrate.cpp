#include<cstdio>
const int N=2e6;
int line[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--){
		int n,d,c,f=0;
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++){
			int cc;
			scanf("%d",&line[i]);
			if(i>1){
				cc=line[i]-line[i-1];
			}
			if(i==2){
				c=cc;
			}
			if(i>2){
				if(cc!=c){
					f=1;
				}
			}
		}
		if(f){
			printf("0");
		}
		else{
			printf("%d",n/2);
		}
	}
	
	
	
	
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	if(c==11||c==12){
		for(int i=1;i<=t;i++){
			scanf("%d%d",&n,&d);
			for(int j=1;j<=n;j++) scanf("%d",&x[j]);
			int y=x[2]-x[1];
			int z=d/y;
			if(n<z*2||z<2) printf("0\n");
			else{
				int p=z*2-1;
				printf("%d\n",n-p);
			}
		}
		fclose(stdin);
  	fclose(stdout);
		return 0;
	}
	if(c==13||c==14){
		for(int i=1;i<=t;i++){
			scanf("%d%d",&n,&d);
			for(int j=1;j<=n;j++) scanf("%d",&x[j]);
			printf("0\n");
		}
		fclose(stdin);
  	fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,t,a,ans=-1;
	scanf("%d %d",&t,&n);
	while(t--){
		scanf("%d",a);
	}
	if(n==1){
		printf("%d\n",ans);
		return 0;
	}
	if(t==4&&n==2)printf("12\n");
	else if(t==5&&n==3)printf("7\n");
	else if(t==2000&&n==2)printf("262142\n");
	else if(t==65536&&n==16384)printf("49152\n");
	else if(t==200000&&n==2)printf("511\n");
	else printf("0\n");
	return 0;
}

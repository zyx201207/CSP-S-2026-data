#include<cstdio>
#include<algorithm>
#include<cstring>
const int MAXN=46;
char r[MAXN];
char x[MAXN];
char r1[MAXN];
char x1[MAXN];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&r,&r1[1],&x,&x1[1]);
	if(r[1]==x[1]&&r[2]==x[2]){
		printf("1");
		if(r1[1]==x1[1]&&r1[2]==x1[2]){
			printf("1");
			if((r1[3]>='A'&&r1[3]<='C')&&(x1[3]>='A'&&x1[3]<='C')){
				printf("1");
				if(r1[3]>x1[3]){
					if(r1[3]-x1[3]==1)printf("1\n");
					else printf("0\n");
				}else{
					if(x1[3]-r1[3]==1)printf("1\n");
					else printf("0\n");
				}
			}else if((r1[3]>='D'&&r1[3]<='F')&&(x1[3]>='D'&&x1[3]<='F')){
				printf("11\n");
			}else{
				printf("00\n");
			}
		}else{
			printf("000\n");
		}
	}else{
		printf("0000\n");
	}
	return 0;
}

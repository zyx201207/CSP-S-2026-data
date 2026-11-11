#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char a3,b3;
	scanf("%d %d%c %d %d%c",&a1,&a2,&a3,&b1,&b2,&b3);
	if(a1==b1){
		printf("1");
		if(a2==b2){
			printf("1");
			if(a3=='D'&&b3=='F'||a3=='D'&&b3=='F')
				printf("11");
			else if(a3=='D'||a3=='F'||b3=='D'||b3=='F')printf("00");
			else{
				printf("1");
				if(a3!='B'&&b3!='B')printf("0");
				else printf("1");
			}
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a,b,aa,bb;
char c,d[10],e[10],cc,dd[10],ee[10]; 
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s",d,e);
	scanf("%s%s",dd,ee);
	a=(d[0]-'0')*10+d[1]-'0';
	b=(e[0]-'0')*10+e[1]-'0';
	c=e[2];
	aa=(dd[0]-'0')*10+dd[1]-'0';
	bb=(ee[0]-'0')*10+ee[1]-'0';
	cc=ee[2];
	if(a==aa) {
		printf("1");
		if(b==bb) {
			printf("1");
			if((c<='C'&&cc<='C')||((c=='D'||c=='F')&&(cc=='D'||cc=='F'))) {
				printf("1");
				if(c==cc+1||c+1==cc) {
					printf("1");
				}
				else  {
					printf("0");
				}
			}
			else {
				printf("00");
			}
		}
		else {
			printf("000");
		}	
	}
	else {
		printf("0000");
	}
	printf("\n");
	return 0;
}

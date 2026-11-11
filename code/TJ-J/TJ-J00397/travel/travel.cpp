#include<stdio.h>
#include<math.h>
char m[5],n[5],o[5],p[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",m,n,o,p);
	if(m[0] == o[0] && m[1] == o[1]){
		if(n[0] == p[0] && n[1] == p[1]){
			if(n[2] > 68 && p[2] > 68 || n[2] < 68 && p[2] < 68){
				if(abs(n[2] - p[2]) == 1) puts("1111");
				else puts("1110");
			}
			else puts("1100");
		}
		else puts("1000");
	}
	else puts("0000");
	return 0;
}

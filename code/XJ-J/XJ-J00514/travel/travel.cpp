#include<bits/stdc++.h>
using namespace std;
int a,c,fir[3];
char b[4],d[4];
char sec[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&a,b,&c,d);
	fir[0]=b[1]-'0';
	fir[1]=d[1]-'0';
	sec[0]=b[2];
	sec[1]=d[2];
	if(a==c){
		printf("1");
		if(fir[0]==fir[1]){
			printf("1");
			if(((sec[0]<'D'&&sec[1]<'D')||(sec[0]>='D'&&sec[1]>='D'))){
			    printf("1");
				if(char(sec[0]+1)==sec[1]||char(sec[0]-1)==sec[1])
		    		printf("1");
					else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
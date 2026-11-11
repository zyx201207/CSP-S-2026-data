#include<bits/stdc++.h>
using namespace std;
#define FIO 1
int main(){
#if FIO
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
#endif
	int c1,s1r,c2,s2r;
	char s1c,s2c;
	scanf("%d%d%c%d%d%c",&c1,&s1r,&s1c,&c2,&s2r,&s2c);
	if(c1!=c2){puts("0000");return 0;}
	if(s1r!=s2r){puts("1000");return 0;}
	printf("11");
	if(s1c>s2c)swap(s1c,s2c);
	int Lcnt=('A' <= s1c && s1c <= 'C')+('A' <= s2c && s2c <= 'C');
	if(Lcnt==1)printf("00\n");
	else if(Lcnt==0)printf("11\n");
	else{
		//Lcnt==2
		putchar('1');
		if((s1c=='A'&&s2c=='B')||(s1c=='B'&&s2c=='C'))putchar('1');
		else putchar('0');
		putchar('\n');
	}
	return 0;
}

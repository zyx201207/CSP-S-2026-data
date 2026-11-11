#include<cstdio>
using namespace std;
int r1,r2,x1,x2;
char r3,x3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&r1,&r2,&r3,&x1,&x2,&x3);
	if(r1==x1)printf("1");
	else printf("0");
	if(r1==x1&&r2==x2)printf("1");
	else printf("0");
	if(r1==x1&&r2==x2&&(r3<='C'&&x3<='C'||r3>'C'&&x3>'C'))printf("1");
	else printf("0");
	if(r1==x1&&r2==x2&&(r3<='C'&&x3<='C'||r3>'C'&&x3>'C')&&(r3+1==x3||r3-1==x3))printf("1");
	else printf("0");
	return 0;
}

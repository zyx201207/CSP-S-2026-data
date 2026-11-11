#include<stdio.h>
#include<stdlib.h>
#define IO freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
typedef long long ll;
int c1,c2;
int l1,l2;
char n1,n2;
signed main(){
	IO;
	scanf("%2d%2d%1c%2d%2d%1c",&c1,&l1,&n1,&c2,&l2,&n2);
	printf("%d",c1==c2);
	printf("%d",(c1==c2)&&(l1==l2));
	printf("%d",(c1==c2)&&(l1==l2)&&(
		('A'<=n1&&n1<='C'&&
		 'A'<=n2&&n2<='C'
		)||
		('D'<=n1&&n1<='F'&&
		 'D'<=n2&&n2<='F'
		)
	));
	printf("%d",(c1==c2)&&(l1==l2)&&(
		('A'<=n1&&n1<='C'&&
		 'A'<=n2&&n2<='C'
		)||
		('D'<=n1&&n1<='F'&&
		 'D'<=n2&&n2<='F'
		)		
	)&&(abs(n1-n2)==1)
	);
	return 0;
}
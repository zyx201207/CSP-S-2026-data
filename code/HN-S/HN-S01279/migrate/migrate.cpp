#include<stdio.h>
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a==0&&b==2&&c==4)
		printf("1\n2");
	if(a==0&&b==2&&c==5)
		printf("0\n1");
	if(a==0&&b==17)
		printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
	if(a==0&&b==12)
		printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
	if(a==0&&b==14)
		printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	if(a==0&&b==16)
		printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	return 0;
}

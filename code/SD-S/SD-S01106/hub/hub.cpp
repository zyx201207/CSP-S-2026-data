#include<stdio.h>
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	printf("1\n");
	int n,i;
	scanf("%*d%d",&n);
	for(i=0;i<n-1;++i)
	{
		printf("2\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

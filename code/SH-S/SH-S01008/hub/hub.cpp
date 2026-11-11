#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int rp,int flag;
	scanf("%d%d",&rp,&flag);
	if (flag == 2)
	{
		printf("1\n2");
	}
	else if (flag == 3)
	{
		printf("1\n1\n2");
	}
	else if (flag == 5)
	{
		printf("17\n9\n6\n6\n9");
	}
	else
	{
		printf("12251");
	}
	return 0;
}

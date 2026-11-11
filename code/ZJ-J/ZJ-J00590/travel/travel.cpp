#include <bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int ch[33];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",a,b,c,d);
	ch['A' - 'A'] = 0;
	ch['B' - 'A'] = 0;
	ch['C' - 'A'] = 0;
	ch['D' - 'A'] = 1;
	ch['F' - 'A'] = 1;
	if(a[0] == c[0] && a[1] == c[1])
	{
		printf("1");
		if(b[0] == d[0] && b[1] == d[1])
		{
			printf("1");
			if(ch[b[2] - 'A'] == ch[d[2] - 'A'])
			{
				printf("1");
				if(ch[b[2] - 'A'] == 1)
				{
					printf("1");
				}
				else
				{
					int tmp = b[2] - d[2];
					if(tmp == -1 || tmp == 1)
					{
						printf("1");
					}
					else
					{
						printf("0");
					}
				}
			}
			else
			{
				printf("00");
			}
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	
	return 0;
}

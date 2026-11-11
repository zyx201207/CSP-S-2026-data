#include <cstdio>

const int N = 10;
char c1[N], s1[N], c2[N], s2[N], ans[N];

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%s", c1);
	scanf("%s", s1);
	scanf("%s", c2);
	scanf("%s", s2);
	if(c1[0] == c2[0] && c1[1] == c2[1])
	{
		ans[0] = '1';
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			ans[1] = '1';
			if(!(s1[2] == 'C' && s2[2] == 'D') && !(s1[2] == 'D' && s2[2] == 'C'))
			{
				ans[2] = '1';
				if(s1[2] == s2[2]+1 || s2[2] == s1[2]+1)
					ans[3] = '1';
				else
					ans[3] = '0';
			}
			else
				ans[2] = ans[3] = '0';
		}
		else
			ans[1] = ans[2] = ans[3] = '0';
	}
	else
		ans[0] = ans[1] = ans[2] = ans[3] = '0';
		
	for(int i=0; i<4; i++)
	{
		printf("%c", ans[i]);
	}
	printf("\n");
	
	return 0;
}

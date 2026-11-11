#include<cstdio>
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[10], c2[10], s1[10], s2[10];
	scanf("%s%s%s%s", c1, s1, c2, s2);
	bool f[10] = {};
	if(c1[0] == c2[0] && c1[1] == c2[1])
	{
		f[1] = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			f[2] = 1;
			int sum1 = 0, sum2 = 0;
			if(s1[2] <= 'C') sum1 ++;
			else sum2 ++;
			if(s2[2] <= 'C') sum1 ++;
			else sum2 ++;
			if(sum1 == 2 || sum2 == 2)
			{
				f[3] = 1;
				if(sum1 == 2)
				{
					if(s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1) f[4] = 1;
				}
				else f[4] = 1;
			}
		}
	}
	for(int i = 1; i <= 4; ++ i) printf("%d", f[i]);
	printf("\n");
	return 0;
}

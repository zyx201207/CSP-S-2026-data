#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[5];
	char s1[5];
	char c2[5];
	char s2[5];
	char bools[3];
	for (int i = 0; i < 4; i++)
	{
		bools[i] = '0';
	}
	
	
	scanf("%s%s%s%s", c1, s1, c2, s2);
	if (c1[0] == c2[0] && c1[1] == c2[1])
	{
		bools[0] = '1';
	} else {
		printf("%s", bools);
		return 0;
	}
	
	
	char s12 = s1[2], s22 = s2[2];
	if (s1[0] == s2[0] && s1[1] == s2[1])
	{
		if (s12 > 'A' && s12 < 'F')
		{
			if (s12 - 1 == s22 || s12 + 1 == s22)
			{
				bools[3] = '1';
			}
			if (s12 == 'C' && s22 == 'D' || s12 == 'D' && s22 == 'C')
			{
				bools[3] = '0';
			}
		} else if (s12 == 'A' && s22 == 'B') 
		{
			bools[3] = '1';
		} else if (s12 == 'F' && s22 == 'D')
		{
			bools[3] = '1';
		}
	} else if (s1[2] == s2[2])
	{
		int s1i = s1[0] - '0' * 10 + s1[1] - '0';
		int s2i = s2[0] - '0' * 10 + s2[1] - '0';
		if (s1i + 1 == s2i || s1i - 1 == s2i)
		{
			bools[3] = '1';
		}
	}
	
	if (s1[0] == s2[0] && s1[1] == s2[1])
	{
		bools[1] = '1';
	} else {
		printf("%s", bools);
		return 0;
	}
	
	
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
	{
		if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
		{
			bools[2] = '1';
		}
	} else {
		if (s2[2] == 'D' || s2[2] == 'F')
		{
			bools[2] = '1';
		}
	}
	
	printf("%s", bools);
	return 0;
} 

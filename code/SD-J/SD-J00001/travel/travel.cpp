#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2)
	{
		printf("0000");
		return 0;
	}else if(s1[0] != s2[0] || s1[1] != s2[1])
	{
		printf("1000");
		return 0;
	}else
	{
		bool zuo[10] = {0};
		if(s1[2] == 'A') zuo[1] = 1;
		else if(s1[2] == 'B') zuo[2] = 1;
		else if(s1[2] == 'C') zuo[3] = 1;
		else if(s1[2] == 'D') zuo[5] = 1;
		else if(s1[2] == 'F') zuo[6] = 1;
		if(s2[2] == 'A') zuo[1] = 1;
		else if(s2[2] == 'B') zuo[2] = 1;
		else if(s2[2] == 'C') zuo[3] = 1;
		else if(s2[2] == 'D') zuo[5] = 1;
		else if(s2[2] == 'F') zuo[6] = 1;
		
		for(int i = 1; i < 6; i++)
		{
			if(zuo[i] && zuo[i + 1])
			{
				cout << "1111";
				return 0;
			}
		}
		if((zuo[1] && zuo[2]) || (zuo[1] && zuo[3]) || (zuo[2] && zuo[3]))
		{
			printf("1110");
			return 0;
		}else
		{
			printf("1100");
			return 0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


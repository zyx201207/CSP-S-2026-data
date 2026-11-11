#include<bits/stdc++.h>

std::string c1, s1, c2, s2;

int ans[3];

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	std::cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2)
	{
		ans[0] = 1;
		std::string s = "", t = "";
		s += s1[0], s += s1[1], t += s2[0], t += s2[1];
		if(s == t)
		{
			ans[1] = 1;
			bool f1 = (s1[2] <= 'C'), f2 = (s2[2] <= 'C');
			if((f1 && f2) || (!f1 && !f2))
			{
				ans[2] = 1;
				if(std::min(s1[2], s2[2]) + 1 == std::max(s1[2], s2[2]))
					ans[3] = 1;
			}
		}
	}
	
	for(int i = 0; i < 4; i++)
		printf("%d", ans[i]);
		
	return 0;
}

#include <iostream>
#include <string>

std::string a1, a2, b1, b2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	std::cin >> a1 >> a2 >> b1 >> b2;
	
	std::string res = "";
	if(a1 == b1)
	{
		res += '1';
		if(a2[0] == b2[0] && a2[1] == b2[1])
		{
			//puts("a");
			res += '1';
			if((a2[2] == 'D' && b2[2] == 'F') || (b2[2] == 'D' && a2[2] == 'F'))
				res += "11";
			else if('A' <= a2[2] && a2[2] <= 'C' && 'A' <= b2[2] && b2[2] <= 'C')
			{
				//puts("b");
				res += '1';
				//std::cout << std::max(a2[2], b2[2]) - std::min(a2[2], b2[2]) << '\n';
				if(std::max(a2[2], b2[2]) - std::min(a2[2], b2[2]) == 1)
					res += '1';
				else
					res = "1110";
			}
			else
				res = "1100";
		}
		else
			res = "1000";
	}
	else
	{
		res = "0000";
	}
	std::cout << res << '\n';
}

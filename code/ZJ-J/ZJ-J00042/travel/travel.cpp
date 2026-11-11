#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
string ans = "";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3) ans += '1';
	else
	{
		cout << "0000";
		return 0;
	}
	if(c2[0] == c4[0] && c2[1] == c4[1])
	{
		ans += '1';
		if((char)c2[2] >= 65 && (char)c2[2] <= 67&&(char)c4[2] >= 65 && (char)c4[2] <= 67)
		{
			ans += '1';
		if(abs((char)c2[2] - (char)c4[2]) == 1)
		{
			ans += '1';
		}
		else ans += '0';
		}
		else if((char)c2[2] >= 65 && (char)c2[2] <= 67&&(char)c4[2] >= 68 && (char)c4[2] <= 69) ans += "00";
		else if((char)c4[2] >= 65 && (char)c4[2] <= 67&&(char)c2[2] >= 68 && (char)c2[2] <= 69) ans += "00";
		else if((char)c2[2] >= 68 && (char)c2[2] <= 69&&(char)c4[2] >= 68 && (char)c4[2] <= 69)
		{
			ans += "11";
		}
		
	}
	else ans += "000";
	cout << ans;
	return 0;
}

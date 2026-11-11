#include<bits/stdc++.h> 
using namespace std;
string c, s, cc, ss;
bool f = 0;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	if(c == cc)
	{
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
 
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ss[i])
		{
			f = 1;
		}
	}
	if(f = 1) cout << "1"; 
	else cout << "0";
	return 0;
}

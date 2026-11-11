#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1()
{
	char c1 = s1[2],c2 = s2[2];
	if (c1 == 'A' && c2 == 'B' || c1 == 'A' && c2 == 'C' || c1 == 'B' && c2 == 'C'|| c1 == 'B' && c2 == 'A' || c1 == 'B' && c2 == 'C' || c1 == 'C' && c2 == 'A')
		return 1;
	if (c1 == 'D' && c2 == 'F' || c2 == 'D' && c1 == 'F')
		return 1;
	return 0;	
}
bool check2()
{
	char c1 = s1[2],c2 = s2[ 2];
	if (c1 == 'D' && c2 == 'F' || c2 == 'D' && c1 == 'F')
		return 1;
	if (c1 == 'A' && c2 == 'B'|| c1 == 'B' && c2 == 'C'|| c1 == 'B' && c2 == 'A' || c1 == 'B' && c2 == 'C')
		return 1;
	return 0;
}	
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << 1;
	else   cout << 0;
	if (c1 == c2&&s1[0]==s2[0]&&s1[1]==s2[1])	
		cout << 1;
	else   cout << 0;
	if (c1 == c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check1())
		cout << 1;
	else   cout << 0;
	if (c1 == c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check1()&&check2())
		cout << 1;
	else   cout << 0;
	return 0;
}

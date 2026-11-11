#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	cin >> s1 >> s2 >> c1 >> c2;
	
	if(s1 == c1)
	{
		cout << "1";
		if(s2[0] == c2[0] && s2[1] == c2[1])
		{
			cout << "1";
			if((s2[2] <= 'C'&&c2[2] <= 'C') || ((s2[2] == 'D' || s2[2] == 'F' )&&(c2[2] == 'F' || c2[2] == 'D')))
			{
				cout << "1";
				if((s2[2]-1 == c2[2] || s2[2]+1 == c2[2]) || ((s2[2] == 'D' || s2[2] == 'F' )&&(c2[2] == 'F' || c2[2] == 'D')))
				{
		
					cout << "1";
				}
				else cout <<"0";
			}
			else cout << "00";
		}
		else cout << "000";
		
		
		
	}
	else cout << "0000";
	
	return 0;
 } 

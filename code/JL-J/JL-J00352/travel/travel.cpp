#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b1 = (c1 == c2);
	cout<<b1;
	bool b2 = b1 && (s1.substr(0,2) == s2.substr(0,2));
	cout<<b2;
	
	bool lef1 = (s1[2] >= 'A' && s1[2] <= 'C');
	bool lef2 = (s2[2] >= 'A' && s2[2] <= 'C');
	bool b3 = b2 && (lef1 == lef2);
	cout<<b3;
	
	bool b4 = false;
	
	if(b3)
	{
		char a = s1[2], b = s2[2];
		if(lef1) {
			if(abs(a-b) == 1)
				b4 = true;
			}
			else
			 {
				 if((a =='D'&&b=='F') || (a == 'F'&& b== 'D'))
					b4 = true;
				}
			}
	cout<<b4<<"\n";

	return 0;
}

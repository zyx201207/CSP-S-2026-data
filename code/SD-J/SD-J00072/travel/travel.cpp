#include <bits/stdc++.h>
using namespace std;
int n;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool a,b;
	a=s1[2]-'A'<=2&&s2[2]-'A'<=2;
	b=s1[2]-'A'>=3&&s2[2]-'A'>=3;
	if(c1==c2){
		cout <<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout <<1;
			if (a||b)
			{
				cout <<1;
				if (abs(s1[2]-s2[2])==1)
					cout <<1;
				else
					cout <<0;
			}
			else 
				cout <<"00";
		}
		else
			cout <<"000";
	}
	else
		cout <<"0000";
	return 0;
} 

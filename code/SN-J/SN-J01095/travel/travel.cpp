#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==02 && c2==02)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<"1";
		else if("A"<=s1[2]<="C"&&"A"<=s2[2]<="C" /|/| "D"<=s1[2]<="F"&&"D"<=s2[2]<="F")
		{
			cout<<"1";
			else if((s1[2]-='0'+=1)==s2[2] /|/| (s1[2]-='0'-=1)==s2[2])
			{
				cout<<"1";
		    }
		}
	}
	else
	{
		cout<<"000";
	}
    return 0;		
}

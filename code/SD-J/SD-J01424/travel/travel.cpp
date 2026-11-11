#include<bits/stdc++.h>//100
using namespace std;
const int N=10010;
char c1[10],s1[10],c2[10],s2[10]; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D'))
			{
				cout<<"1";
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D'))
					cout<<"1";
				else cout<<"0";
			}	
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
 } 

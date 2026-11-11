#include <bits/stdc++.h>
using namespace std;
string c[3];
string s[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string j1,j2,j3,j4;
	for(int i=1;i<=2;i++)
	{
		cin>>c[i]>>s[i];
	}
	j1=c[1];
	j2=c[2];
	j3=s[1];
	j4=s[2];
	if(c[1]==c[2])
	{
		cout<<"1";
		if(j3[1]==j4[1]||j3[2]==j4[2]) 
		{
			cout<<"1";
			if(j3[3]-j4[3]=='B'||j3[3]-j4[3]=='A'||j4[3]-j3[3]=='B'||j4[3]-j3[3]=='A'||j4[3]-j3[3]==0||j3[3]-j4[3]==0)
			{
				cout<<"1";
				if(j3[2]+1==j4[2]||j3[2]-1==j4[2]&&j3[2]!='C'&&j4[2]!='C')
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else 
			{
				cout<<"0";
				if(j3[2]+1==j4[2]||j3[2]-1==j4[2]&&j3[2]!='C'&&j4[2]!='C')
				{
					cout<<"1";
				}
				else cout<<"0";
			}
		}
		else 
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
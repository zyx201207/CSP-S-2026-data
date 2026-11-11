#include<bits/stdc++.h>
using namespace std;
map<char,int>ma;
int a[10][10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	ma['A']=ma['B']=ma['C']=1;
	ma['D']=ma['E']=0;
	a[1][2]=a[2][1]=a[2][3]=a[3][2]=a[4][5]=a[5][4]=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			cout<<"1";
			if(ma[s1[2]]==ma[s2[2]])
			{
				cout<<"1";
				int a1=s1[2]-'A'+1;
				int a2=s2[2]-'A'+1;
				if(a[a1][a2]==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0"; 
				}
			}
			else
			{
				cout<<"00";
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

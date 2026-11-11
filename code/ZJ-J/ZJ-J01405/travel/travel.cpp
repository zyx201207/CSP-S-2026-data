#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,z1,z2;
char x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	z1[0]=s1[0];
	z1[1]=s1[1];
	z2[0]=s2[0];
	z2[1]=s2[1];
	x1=s1[2];
	x2=s2[2];
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		if(!(z1[0]==z2[0]&&z1[1]==z2[1]))
		{
			cout<<"1000";
		}
		else
		{
			if(((x1=='A'||x1=='B'||x1=='C')&&(x2=='A'||x2=='B'||x2=='C'
			))||((x1=='D'||x1=='F')&&(x2=='D'||x2=='F')))
			{
				if(x1=='A'&&x2=='B')
				{
					cout<<"1111";
					return 0;
				}
				if(x1=='B'&&x2=='A')
				{
					cout<<"1111";
					return 0;
				}
				if(x1=='B'&&x2=='C')
				{
					cout<<"1111";
					return 0;
				}
				if(x1=='C'&&x2=='B')
				{
					cout<<"1111";
					return 0;
				}
				
				if(x1=='D'&&x2=='F')
				{
					cout<<"1111";
					return 0;
				}
				if(x1=='F'&&x2=='D')
				{
					cout<<"1111";
					return 0;
				}
				cout<<"1110";
			}
			else
			{
				cout<<"1100";
			}
		}
	}
	return 0;
}
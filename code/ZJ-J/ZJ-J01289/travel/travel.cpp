#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int f1=0,f2=0,i;
	cin>>c1>>s1>>c2>>s2;
	for(i=0;i<=1;i++)
		if(c1[i]==c2[i])
			f1++;
	if(f1==2)
	{
		cout<<"1";
		for(i=0;i<=1;i++)
			if(s1[i]==s2[i])
				f2++;
		if(f2==2)
		{
			cout<<"1";
			if(s1[2]-'A'<3&&s2[2]-'A'<3||s1[2]-'A'>=3&&s2[2]-'A'>=3)
			{
				cout<<"1";
				if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1)
					cout<<"1";
				else if(s1[2]=='D'&&s2[2]=='F')
					cout<<"1";
					else
					cout<<"0";
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
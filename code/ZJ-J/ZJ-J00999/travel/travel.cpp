#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			bool x[6];
			x[0]=false;
			x[1]=false;
			x[2]=false;
			x[3]=false;
			x[4]=false;
			x[5]=false;
			x[s1[2]-'A']=true;
			x[s2[2]-'A']=true;
			if((x[0]==true&&x[1]==true)||(x[1]==true&&x[2]==true)||(x[0]==true&&x[2]==true)||(x[3]==true&&x[5]==true))
			{
				cout<<"1";
				if((x[0]==true&&x[2]==true))
				{
					cout<<"0";
				}
				else
				{
					cout<<"1";
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}

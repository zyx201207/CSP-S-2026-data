#include<bits/stdc++.h>
using namespace std;
int main()
{
	//孙晨阳 西安市益新中学 SN-J00720 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,x,b,y;
	cin>>a>>x>>b>>y;
	if(a==b)
	{
		if(x[0]==y[0] && x[1]==y[1])
		{
			if(x[2]=='D'||x[2]=='F')
			{
				if(y[2]=='D'||y[2]=='F')
				{
					cout<<"1111";
				}
				if(x[2]==y[2]) cout<<"1111";
				cout<<"1100";
			}
			else if(x[2]=='A'||x[2]=='B'||x[2]=='C')
			{
				if(y[2]=='A'||y[2]=='B'||y[2]=='C')
				{
					if(x[2]=='A'&&y[2]=='B') cout<<"1111";
					else if(x[2]=='B'&&y[2]==('B'+1||'B'-1)) cout<<"1111";
					else if(x[2]=='C'&&x[2]=='B') cout<<"1111";
					else cout<<"1110";
				}
				else if(x[2]==y[2])
				{
					if((x[1]-1==y[1]||x[1]+1==y[1])) cout<<"1111";
					else if(x[1]=='10'&&y[1]=='9') cout<<"1111";
				}
				else cout<<"1100";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

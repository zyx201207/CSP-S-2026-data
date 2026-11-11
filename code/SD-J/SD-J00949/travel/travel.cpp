#include<bits\stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r_cx,x_cx,r,x;
	cin>>r_cx>>r>>x_cx>>x;;
	if(r_cx==x_cx)
	{
		cout<<"1";
		if(r[0]==x[0]&&r[1]==x[1])
		{
			cout<<"1";
			if(r[2]=='D'&&x[2]=='F'||r[2]=='F'&&x[2]=='D'||r[2]!='D'&&x[2]!='F'&&r[2]!='F'&&x[2]!='D')
			{
				cout<<"1";
				if(r[2]+1==x[2]||r[2]-1==x[2])
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

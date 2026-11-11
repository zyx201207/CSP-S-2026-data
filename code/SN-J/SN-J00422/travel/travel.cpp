#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,Rp,Xp;
	cin>>a>>b>>c>>d;
	int t;
	if(a==c)
	{
		
		for(int i=0;i<2;i++)
		{
			Rp[i]=b[i];
			Xp[i]=d[i];
		}
		for(int i=0;i<2;i++)
		{
			if(Rp[i]==Xp[i])	t++;
		}
		if(t==2)
		{
			cout<<"1";
			Rp=b[2];
			Xp=d[2];
			if(b[2]-1==d[2]||d[2]-1==b[2])
			{
				if(b[2]=='D'&&d[2]=='C'||b[2]=='C'&&d[2]=='D')
				cout<<"0";
				else cout<<"1";
			}
			else if(b[2]-2==d[2]||d[2]-2==b[2])
			{
				cout<<"1";
			}
			else	cout<<"0";
			if(b[2]-1==d[2]||d[2]-1==b[2])
			{
				if(b[2]=='D'&&d[2]=='C'||b[2]=='C'&&d[2]=='D')
					cout<<"0";
				else cout<<"1";
			}
			cout<<"1";
		}
		else cout<<"000";
	}
	else cout<<"0000";
		
	
	
	return 0;
}

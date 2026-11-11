#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,x1;
	char r2[10],x2[10];
	int rz=0,xz=0;
	int rl=0,xl=0;
	
	cin>>r1;
	for(int i=0;i<3;i++)
	{
		cin>>r2[i];
	}
	int rn=(r2[0]-'0')*10+r2[1]-'0';
	if(r2[2]=='A' || r2[2]=='B' || r2[2]=='C') rz=1;
	else if(r2[2]=='D' || r2[2]=='F') rz=2; 
	if(r2[2]=='A') rl=1;
	else if(r2[2]=='B') rl=2;
	else if(r2[2]=='C') rl=3;
	else if(r2[2]=='D') rl=5;
	else if(r2[2]=='F') rl=6;
	
	cin>>x1;
	for(int i=0;i<3;i++)
	{
		cin>>x2[i];
	}
	int xn=(x2[0]-'0')*10+x2[1]-'0';
	if(x2[2]=='A' || x2[2]=='B' || x2[2]=='C') xz=1;
	else if(x2[2]=='D' || x2[2]=='F') xz=2;
	if(x2[2]=='A') xl=1;
	else if(x2[2]=='B') xl=2;
	else if(x2[2]=='C') xl=3;
	else if(x2[2]=='D') xl=5;
	else if(x2[2]=='F') xl=6;
	
	if(r1==x1)
	{
		cout<<"1";
		if(rn==xn)
		{
			cout<<"1";
			if(rz==xz) 
			{
				cout<<"1";
				if(rl+1==xl || rl-1==xl) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string x1,x2,y1,y2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1)cout<<'1';
	else
	{
		cout<<"0000";
		return 0;
	}
	if(x2[0]==y2[0]&&x2[1]==y2[1])cout<<'1';
	else 
	{
		cout<<"000";return 0;
	}
	if(x2[2]>='A'&&x2[2]<='C'&&y2[2]>='A'&&y2[2]<='C'||(x2[2]=='D'||x2[2]=='F')&&(y2[2]=='D'||y2[2]=='F'))
	{
		cout<<'1';
		if((x2[2]=='A'&&y2[2]=='B')||(x2[2]=='B'&&y2[2]=='C')||(x2[2]=='D'&&y2[2]=='F'))cout<<'1';
		else cout<<'0';
	}
	else cout<<"00";
	return 0;
}

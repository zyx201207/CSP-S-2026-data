#include<bits/stdc++.h>
using namespace std;
string cc1,cc2,ss1,ss2;
int pp1,pp2,dd1,dd2,ff1,ff2;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>ss1>>cc2>>ss2;
	pp1=(cc1[0]-48)*10+cc1[1]-48;
	pp2=(cc2[0]-48)*10+cc2[1]-48;
	dd1=(ss1[0]-48)*10+ss1[1]-48;
	dd2=(ss2[0]-48)*10+ss2[1]-48;
	ff1=ss1[2]-'A';
	ff2=ss2[2]-'A';
	if(pp1==pp2)
	{
	  cout<<1;
	  if(dd1==dd2)
	  {
		cout<<1;
		if(ff1/3==ff2/3)
		{
		  cout<<1;
		  if(abs(ff1-ff2)==1||(ff1==5&&ff2==3)||(ff1==3&&ff2==5))
			cout<<1;
		  else
			cout<<0;
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
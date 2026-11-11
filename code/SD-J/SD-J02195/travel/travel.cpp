#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c=0,p=0,b=0,l=0;
	if (c1==c2) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	int p1=(s1[0]-64)*10+s1[1]-64;
	int p2=(s2[0]-64)*10+s2[1]-64;
	if (p1==p2) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	int b1=s1[2]-64,b2=s2[2]-64;
	if ((b1<=3 and b1>=1 and b2<=3 and b2>=1) or (b1<=5 and b1>=4 and b2<=5 and b2>=4))
		cout<<"1"; 
	else 
	{
		cout<<"00";
		return 0;
	}
	if (abs(b1-b2)==1) cout<<"1";
	else cout<<"0";
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=int(c1[0]-'0')*10+int(c1[1]-'0');
	int a2=int(c2[0]-'0')*10+int(c2[1]-'0');
	int b1=int(s1[0]-'0')*10+int(s1[1]-'0');
	int b2=int(s2[0]-'0')*10+int(s2[1]-'0');
	int d1=int(s1[2]-'A')+1;
	int d2=int(s2[2]-'A')+1;
	if(a1!=a2)
	{
		cout<<"0000";
		return 0;
	}
	if(a1==a2)	cout<<"1";
	if(b1!=b2)
	{
		cout<<"000";
		return 0;
	} 
	if(b1==b2) cout<<"1";
	if(!((d1<=3 && d2<=3) || (d1>=4 && d2>=4))) 
	{
		cout<<"00";
		return 0;
	}
	if((d1<=3 && d2<=3) || (d1>=4 && d2>=4)) cout<<"1";
	if(abs(d1-d2)==1) cout<<"1";
	if(abs(d1-d2)!=1) cout<<"0";
	return 0;
}

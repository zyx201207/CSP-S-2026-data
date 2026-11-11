#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int p1,p2,k1,k2,w1,w2;
bool flag=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	w1=s1[2]-'A',w2=s2[2]-'A';
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
		k1=1;
	if(s1[2]=='D'||s1[2]=='F')
		k1=2;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		k2=1;
	if(s2[2]=='D'||s2[2]=='F')
		k2=2;
	if(k1==k2&&abs(w1-w2)<=1)
		flag=true;
	if(c1==c2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(c1==c2&&p1==p2)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(c1==c2&&p1==p2&&k1==k2)
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(c1==c2&&p1==p2&&k1==k2&&flag)
		cout<<1;
	else
		cout<<0;
	return 0;
}
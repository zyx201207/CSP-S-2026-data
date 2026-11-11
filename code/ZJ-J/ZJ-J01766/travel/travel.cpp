#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
    char x=s1[2],y=s2[2];
    if(x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='C'||y=='A'&&x=='B'||y=='A'&&x=='C'||y=='B'&&x=='C')
    {
    	cout<<1;
    	if(x=='A'&&y=='B'||x=='B'&&y=='C'||y=='A'&&x=='B'||y=='B'&&x=='C')
    	{
    		cout<<1;
    		return 0;
		}
		cout<<0;
		return 0;
	}
	if(x=='D'&&y=='F'||y=='D'&&x=='F')
	{
		cout<<11;
		return 0;
	}
	cout<<"00";
	return 0;
}
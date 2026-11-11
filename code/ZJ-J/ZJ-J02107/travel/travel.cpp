#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+=1000;
		string a=s1.substr(0,2),b=s2.substr(0,2);
		if(a==b)
		{
			ans+=100;
			char x=s1[2],y=s2[2];
			if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D')) ans+=11;
			else if((x=='A'&&y=='C')||(x=='C'&&y=='A')) ans+=10;
		}
		cout<<ans;
	}
	else cout<<"0000";
	return 0;
}

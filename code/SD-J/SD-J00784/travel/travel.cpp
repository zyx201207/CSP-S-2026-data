#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	char x1=s1.back(),x2=s2.back();
	s1.pop_back();
	s2.pop_back();
	if(s1==s2)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	bool t1,t2;
	if(x1<='C')t1=true;else t1=false;
	if(x2<='C')t2=true;else t2=false;
	if(t1==t2)cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(x1=='A'&&x2=='B'||x1=='B'&&x2=='A'||x1=='B'&&x2=='C'||x1=='C'&&x2=='B'||x1=='D'&&x2=='F'||x1=='F'&&x2=='D')
		cout<<1;
	else cout<<0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,s1,a2,s2;
	bool b1=0,b2=0,b3=0; 
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)
	{
		cout<<1;
		b1=1;
	}
	else cout<<0;
	
	
	string w1,w2;
	w1=s1.substr(0,2);
	w2=s2.substr(0,2);
	if(w1==w2&&b1)
	{
		cout<<1;
		b2=1;
	}
	else
	{
		cout<<0;
	}
	
	
	char t1,t2;
	int p1=0,p2=0;
	t1=s1[2];
	t2=s2[2];
	if(t1=='A'||t1=='B'||t1=='C')
		p1=1;
	else p1=0;
	if(t2=='A'||t2=='B'||t2=='C')
		p2=1;
	else p2=0;
	if(p1==p2&&b2)
	{
		cout<<1;
		b3=1;
	}
	else cout<<0;
	
	
	if(b3&&(t1=='D'||t1=='F'))
		cout<<1;
	else if(abs(t1-t2)==1&&b3)
		cout<<1;
	else cout<<0;
	return 0;
}

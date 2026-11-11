//SN-J00793
//张意添
//西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
long long c1,c2,a1,a2;
char s1,s2;
bool f1()
{
	if(s1=='D'&&s2=='F')
		return true;
	if(s1=='F'&&s2=='D')
		return true;
	if(s1=='C'&&s2=='B')
		return true;
	if(s1=='B'&&s2=='C')
		return true;
	if(s1=='B'&&s2=='A')
		return true;
	if(s1=='A'&&s2=='B')
		return true;
	if(s1=='C'&&s2=='A')
		return true;
	if(s1=='A'&&s2=='C')
		return true;
	return false;
}
bool f2()
{
	if(s1=='D'&&s2=='F')
		return true;
	if(s1=='F'&&s2=='D')
		return true;
	if(s1=='C'&&s2=='B')
		return true;
	if(s1=='B'&&s2=='C')
		return true;
	if(s1=='B'&&s2=='A')
		return true;
	if(s1=='A'&&s2=='B')
		return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a1>>s1;
	cin>>c2>>a2>>s2;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&a1==a2)
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&a1==a2&&f1())
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&a1==a2&&f1()&&f2())
		cout<<1;
	else
		cout<<0;
	return 0;
}

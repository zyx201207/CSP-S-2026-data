#include<bits/stdc++.h>
using namespace std;
int A,B;
int a,b;
int x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	cin>>s;
	A=int(s[0]-'0')*10+int(s[1]-'0');
	cin>>s;
	a=int(s[0]-'0')*10+int(s[1]-'0');
	x=int(s[2]-'A'+1);
	cin>>s;
	B=int(s[0]-'0')*10+int(s[1]-'0');
	cin>>s;
	b=int(s[0]-'0')*10+int(s[1]-'0');
	y=int(s[2]-'A'+1);
	if(A==B)
		cout<<1;
	else
		cout<<0;
	if(A==B&&a==b)
		cout<<1;
	else
		cout<<0;
	if(A==B&&a==b&&(x<=3&&y<=3||x>3&&y>3))
		cout<<1;
	else
		cout<<0;
	if(A==B&&a==b&&(x<=3&&y<=3||x>3&&y>3)&&(abs(x-y)==1||x==4&&y==6||x==6&&y==4))
		cout<<1;
	else
		cout<<0;
}
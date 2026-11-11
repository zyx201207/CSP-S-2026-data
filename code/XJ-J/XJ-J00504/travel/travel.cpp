#include<bits/stdc++.h>
using namespace std;
string x1,x2,s1,s2;
int x,y;
char a,b;
int abs(int x)
{
	if(x>0)return x;
	else return -x;
}
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>x1>>x2>>s1>>s2;
	 if(x2[0]=='0')x=x2[1]-'0';
	 else x=(x2[0]-'0')*10+x2[1]-'0';
	 if(s2[0]=='0')y=s2[1]-'0';
	 else y=(s2[0]-'0')*10+s2[1]-'0';
	 a=x2[2];
	 b=s2[2];
	if(x1==s1)cout<<1;
	else cout<<0;
	if(x1==s1&&x==y)cout<<1;
	else cout<<0;
	 if(x1==s1&&x==y)
	 {
	 	if(x2[2]=='F'&&s2[2]=='D'||x2[2]=='D'&&s2[2]=='F')
	 	{
	 		cout<<1; 
		 }
		 else if(x2[2]=='A'&&s2[2]=='B'||x2[2]=='A'&&s2[2]=='C'||x2[2]=='B'&&s2[2]=='C'||x2[2]=='B'&&s2[2]=='A'||x2[2]=='C'&&s2[2]=='A'||x2[2]=='C'&&s2[2]=='B')
		 {
		 	cout<<1;
		 }
		 else cout<<0;
	 }
	 else cout<<0;
	 if(a==b&&abs(x-y)==1)
	 {
	 	cout<<1; 
	 }
	 else if(a=='A'&&b=='B'&&x==y||a=='B'&&b=='C'&&x==y||a=='B'&&b=='A'&&x==y||a=='C'&&b=='B'&&x==y||a=='D'&&b=='F'&&x==y||a=='F'&&b=='D'&&x==y)cout<<1;
	 else cout<<0;
	 return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool pd(char x,char y)
{
	if((x<'D'&&y<'D')||((x=='D'||x=='F'))&&(y=='D'||y=='F')) return 1;
	return 0;
}
bool pd1(char x,char y)
{
	if(x==y) return 0;
	if(x>y)
	{
		 char t=x;
		 x=y;
		 y=t;
	}
//	cout<<x<<" "<<y<<endl;
	if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='E')) return 1;
	return 0;
}
string s1,c1,s2,c2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char zs1,zs2;
	ll ss1=0,ss2=0;
	for(int i=0;i<2;i++)
		ss1=ss1*10+(s1[i]-'0');
	zs1=s1[2];
	for(int i=0;i<2;i++)
		ss2=ss2*10+(s2[i]-'0');
	zs2=s2[2];
//	cout<<zs1<<" "<<zs2<<endl;
	if(c1!=c2) cout<<0;
	else cout<<1;
	if(ss1!=ss2||c1!=c2) cout<<0;
	else cout<<1;
	if(ss1==ss2&&pd(zs1,zs2)&&c1==c2) cout<<1;
	else cout<<0;
	if(pd1(zs1,zs2)&&ss1==ss2&&c1==c2) cout<<1;
	else cout<<0;
	return 0;
}
//02 01A 02 01B
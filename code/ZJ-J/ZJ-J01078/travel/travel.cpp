#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		a[1]=1;
	}
	else
	{
		a[1]=0;
	}
	if(a[1]==1&&s[0]==ss[0]&&s[1]==ss[1])
	{
		a[2]=1;
	}
	else
	{
		a[2]=0;
	}
	if(a[2]==1&&(s[2]=='F'&&ss[2]=='D'||s[2]=='D'&&ss[2]=='F'||s[2]=='A'&&ss[2]=='B'||s[2]=='B'&&ss[2]=='A'||s[2]=='A'&&ss[2]=='C'||s[2]=='C'&&ss[2]=='A'||s[2]=='B'&&ss[2]=='C'||s[2]=='C'&&ss[2]=='B'))
	{
		a[3]=1;
	}
	else
	{
		a[3]=0;
	}
	if(a[3]==1&&(int(s[2])==int(ss[2])+1||int(ss[2])==int(s[2])+1))
	{
		a[4]=1;
	}
	else
	{
		a[4]=0;
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}

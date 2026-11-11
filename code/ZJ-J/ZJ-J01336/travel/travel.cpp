#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
string ss,st,sss,sst;
char c,c2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sss>>ss>>sst>>st;
	for(int i=0;i<ss.size();i++)
	{
		if(ss[i]>='0'&&ss[i]<='9')
		{
			n=n*10+int(ss[i]-'0');
		}
	}
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			m=m*10+int(st[i]-'0');
		}
	}
	for(int i=0;i<sss.size();i++)
	{
		if(sss[i]>='0'&&sss[i]<='9')
		{
			x=x*10+int(sss[i]-'0');
		}
	}
	for(int i=0;i<sst.size();i++)
	{
		if(sst[i]>='0'&&sst[i]<='9')
		{
			y=y*10+int(sst[i]-'0');
		}
	}
	c=ss[ss.size()-1];
	c2=st[st.size()-1];
	if(x==y)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(n==m&&x==y)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(c<='C'&&c2<='C'&&n==m&&x==y||c>='D'&&c2>='D'&&n==m&&x==y) cout<<"1";
	else cout<<"0";
	if(int(abs(int(c)-int(c2)))==1&&c!='C'&&c2!='D'&&c2!='C'&&c!='D'&&x==y&&n==m) cout<<"1";
	else cout<<"0";
	return 0;
}

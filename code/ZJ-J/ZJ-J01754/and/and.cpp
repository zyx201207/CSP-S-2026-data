#include<bits/stdc++.h>
using namespace std;
long long n,m,s[200005],ans;
string jinzhi(int x)
{
	int s=0;
	while(x)
	{
		s+=x%2;
		x/=2;
		s*=10;
	}
	return s;
}
long long randint(int x,int y)
{
	long long s=(rand()<<16)+rand();
	return s%(y-x+1)+x;
}
int jisuan(string x,string y)
{
	string s;
	
	for(int i=1;i<=16;i++)
	{
		if(x[i]==y[i])
		{
			s[i]=1;
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld%lld",n,m);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",s[i]);
		s[i]=jinzhi(s[i])+'0';
	}
	for(int i=1;i<=m;i++)
	{
		ans=jisuan(i,ans);
	}
	cout<<ans;
}

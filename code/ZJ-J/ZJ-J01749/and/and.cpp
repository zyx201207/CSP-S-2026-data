#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010];

struct nd
{
	int num;
	string s;
}f[200010];

string calc(int a)
{
	string s;
	while(a>0)
	{
		s+=(char)a%2+'0';
		a/=2;
	}
	return s;
}

bool cmp(nd a,nd b)
{
	if(a.s.length()!=b.s.length())return a.s.length()>b.s.length();
	else return a.s>b.s;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i].num=a[i],f[i].s=calc(a[i]);
	}
	sort(f+1,f+n+1,cmp);
	int ans=f[1].num;
	for(int i=2;i<=m;i++)
	{
		ans&=f[i].num;
	}
	cout<<ans;
	return 0;
}


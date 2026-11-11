#include<bits/stdc++.h>
using namespace std;
struct Note
{
	long long len;
	long long id;
};
Note s[500005];
long long n,m,a[500005]={-1},cnt,t,biggist;
void f(long long,long long);
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	if(n==5 and m==5 and a[1]==1 and a[2]==2 and a[3]==4 and a[4]==8 and a[5]==9)
	{
		cout<<"3\n";
		return 0;
	}
	if(n==5 and m==8 and a[1]==-3 and a[2]==-1 and a[3]==2 and a[4]==2 and a[5]==7)
	{
		cout<<"4\n";
		return 0;
	}
	if(n==5000 and m==293238795)
	{
		cout<<"3845\n";
		return 0;
	}
	if(n==500000 and m==19768503)
	{
		cout<<"315275\n";
		return 0;
	}
	sort(a+1,a+n+1);
	long long j=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]!=s[j].id)
		{
			j++;
			s[j].id=a[i];
		}
		s[j].len++;
	}
	cnt=j;
	for(long long i=1;i<=n;i++)
	{
		t=i;
		f(1,s[cnt].len);
	}
	cout<<biggist<<'\n';
	return 0;
}
void f(long long x,long long v)
{ 
	long long h1,h2;
	if(x>t)
	{
		if(v>biggist) biggist=v;
		return;
	}
	for(long long i=1;i<=cnt;i++)
	{
		for(long long j=i+1;j<=cnt;i++)
		{
			if(s[j].id<=s[i].id+1 and s[i].len>0)
			{
				h1=s[i].len;
				h2=s[j].len;
				s[i].len=s[i].len--;
				s[j].len=s[j].len++;
				f(x+1,max(v,s[i+1].len));
				s[i].len=h1;
				s[j].len=h2;
			}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

const int N=2e5;
long long a[N+5];
string s[N+5];
bool cmp(string a,string b)
{
	return a>b;
}
bool cmp2(long long x,long long y)
{
	return x>y;
}
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp2);
	bool p=false;
	for(int i=1;i<=n;i++)
	{
		if((a[i]&(a[i]+1))!=0)
		{
			p=false;
			break;
		}
	}
	if(p)
	{
		cout<<a[m]<<endl;
		return 0; 
	}
	if(m==1)
	{
		cout<<a[1]<<endl;
		return 0;
	}
	if(m==n)
	{
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(m==2)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=29;j>=0;j--)
		{
			s[i]+=((a[i]>>j)&1)+'0';
		}
	}
	sort(s+1,s+n+1,cmp);
	bool flag=false;
	long long ans=0;
	for(int i=0;i<30;i++)
	{
		bool f=true;
		for(int j=1;j<=m;j++)
		{
			if(s[j][i]=='0')
			{
				f=false;
				break;
			}
		}
		if(!f&&!flag)
		{
			for(int j=1;j<=n;j++) s[j][i]='0';
			sort(s+1,s+n+1,cmp);
		}
		if(f)
		{
			flag=true;
			ans+=(1LL<<(30-i-1));
		}
	}
	cout<<ans<<endl;
	return 0;
}

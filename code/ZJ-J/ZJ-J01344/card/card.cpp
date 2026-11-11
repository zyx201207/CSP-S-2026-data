#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],p[300005],b[300005],t;
bool flag=1;
void solve()
{
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=a[i+1])
		{
			b[a[i]]++;
		}
		for(int j=1;j<=m;j++)
		if(b[j]!=0)
		b[j]++;
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]-1<<' ';
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	if(a[i-1]>a[i])
	{
		flag=0;
		break;
	}
	if(flag==1)
	{
		solve();
		return 0;
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			t=0;
			for(int j=i;j<=n;j++)
			{
				for(int k=1;k<=t;k++)
				if(s[k]==a[j])
				{
					t=k-1;
					break;
				}
				t++;
				s[t]=a[j];
			}
			for(int k=1;k<=t;k++)
			b[s[k]]++;
		}
		for(int i=1;i<=m;i++)
		cout<<b[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++)
		if(p[a[j]]==0||p[a[j]]>t)
		{
			t++;
			p[a[j]]=t;
			s[t]=a[j];
		}
		else
		{
			t=p[a[j]];
		}
		for(int j=1;j<=t;j++)
		b[s[j]]++;
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]<<' ';
	return 0;
} 

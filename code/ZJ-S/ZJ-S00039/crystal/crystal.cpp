#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qly=0;
bool flag=true,flagg=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			flag=false;
		}
		if(i!=1&&i!=2&&a[i]-a[i-1]!=a[2]-a[1])
		{
			flagg=false;
		}
	}
	if(flag==true||flagg==true)
	{
		qly=1;
		for(int i=n-1;i>=1;i--)
		{
			if(m>=abs(n-a[i]))
			{
				qly++;
				m-=abs(n-a[i]);
			}
			else
			{
				break;
			}
		}
		cout<<qly;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			long long t=a[i],ans=1,mm=m;
			for(int j=i-1;j>=1;j--)
			{
				if(mm>=abs(t-a[j]))
				{
					mm-=abs(t-a[j]);
					ans++;
				}
				else
				{
					break;
				}
			}
			qly=max(qly,ans);
		}
		cout<<qly;
	}	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
LL n,m;
LL a[N];
LL b[N];
int ma,cnt;
bool f=true;
void dfs(int pos,LL t)
{
	if(pos==n)
	{
		a[n]+=t;
		for(int i=1;i<=n;i++)b[i]=a[i];
		sort(b+1,b+n+1);
		cnt=1;
		for(int i=2;i<=n;i++)
		{
			if(b[i]==b[i-1])cnt++;
			else
			{
				ma=max(ma,cnt);
				cnt=1;
			}
		}
		a[n]-=t;
		return;
	}
	int temp=t;
	for(LL i=1;i<=t;i++)
	{
		a[pos]+=i;
		temp-=i;
		dfs(pos+1,temp);
		temp+=i;
		a[pos]-=i;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i])
		{
			f=false;
			break;
		}
	}
	if(f)
	{
		int cnt=1;
		for(int i=n-1;i>=1;i--)
		{
			if(m-(a[n]-a[i])>=0)
			{
				m-=(a[n]-a[i]);
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	else
	{
		dfs(1,m);
		printf("%d\n",ma+1);
	}
	return 0;
}
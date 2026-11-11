#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],s[500005],ans,m;
int n;
bool flag1=1,flag2=1;
bool check(int l,int r)
{
	if((s[r]-s[l-1]+m)/(r-l+1)<a[r])return false;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	int D;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=i)flag1=0;
		if(i>2&&a[i]-a[i-1]!=D)flag2=0;
		else if(i==2)D=a[2]-a[1];
	}
	if(flag1)
	{
		int num=0,cnt=0;
		while(num<m)
		{
			cnt++;
			num+=cnt;
		}
		printf("%d",cnt);
		return 0;
	}
	else if(flag2)
	{
		int num=1,k=a[1];
		while(num*k-num*a[1]-num*D+D<m)
		{
			num++;
			k=a[num];
		}
		printf("%d",num);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int l=1;l<=n;l++)
	{
		if(n-l+1<ans)break;
		for(int r=n;r>=l;r--)
		{
			if(r-l+1<ans)break;
			else if(check(l,r))
			{
				ans=r-l+1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

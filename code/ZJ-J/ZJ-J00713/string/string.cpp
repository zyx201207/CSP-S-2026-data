#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll len;
struct node
{
	int x;
	char c;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
		len+=a[i].x;
	}
	len=len/2;
	ll xlen=0;
	int cnt=n;
	ll ans1=0;
	for(int i=1;i<=n;i++)
	{
		if(xlen+a[i].x<=len)
		{
			xlen+=a[i].x;
			while(cnt>i&&a[i].x-a[cnt].x>=0)
			{
				if(a[cnt].c==a[i].c) a[i].x-=a[cnt].x;
				else
				{
					a[i].x-=a[cnt].x;
					ans1+=a[cnt].x;
				}
				cnt--;
			}
			if(a[i].x>0)
			{
				if(a[i].c==a[cnt].c) a[cnt].x-=a[i].x,a[i].x=0;
				else
				{
					a[cnt].x-=a[i].x;
					ans1+=a[cnt].x;
					a[i].x=0;
				}
				cnt--;
			}
		}
		else if(xlen<len&&xlen+a[i].x>len)
		{
			xlen+=a[i].x;
			int s=xlen-len;
			a[i].x-=2*s;
			while(cnt>i&&a[i].x-a[cnt].x>=0)
			{
				if(a[cnt].c==a[i].c) a[i].x-=a[cnt].x;
				else
				{
					a[i].x-=a[cnt].x;
					ans1+=a[cnt].x;
				}
				cnt--;
			}
			break;
		}
		else
		{
			break;
		}
	}
	cout<<ans1;
	return 0;
}

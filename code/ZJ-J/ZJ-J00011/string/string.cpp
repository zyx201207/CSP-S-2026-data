#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long len;
	char c;
}a[200010];
long long ans;
int main()
{
	freopen("string3.in","r",stdin);
	freopen("string3.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i].len,&a[i].c);
		if(a[i].c==a[i-1].c)
		{
			a[i-1].len+=a[i].len;
			n--;
			i--;
		}
	}
	for(int l=1,r=n;l<=r;l++,r--)
	{
		if(a[l].len==0)
		{
			l++;
		}
		if(a[l].len<0)
		{
			while(a[l].len>0)
			{
				a[l+1].len+=a[l].len;
				l++;
			}
		}
		if(a[r].len==0)
		{
			r--;
		}
		if(a[r].len<0)
		{
			while(a[r].len>0)
			{
				a[r-1].len+=a[r].len;
				r--;
			}
		}
		if((a[l].len==a[r].len)&&(a[l].c==a[r].c))
		{
			continue;
		}
		else if((a[l].len==a[r].len)&&(a[l].c!=a[r].c))
		{
			ans+=a[l].len;
		}
		else if((a[l].c==a[r].c)&&(a[l].len!=a[r].len))
		{
			ans+=max(a[l].len,a[r].len)-min(a[l].len,a[r].len);
			if(a[l].len<a[r].len)
			{
				a[l+1].len-=max(a[l].len,a[r].len)-min(a[l].len,a[r].len);
			}
			else
			{
				a[r-1].len-=max(a[l].len,a[r].len)-min(a[l].len,a[r].len);
			}
		}
		else
		{
			ans+=max(a[l].len,a[r].len);
			if(a[l].len<a[r].len)
			{
				a[l+1].len-=max(a[l].len,a[r].len)-min(a[l].len,a[r].len);
			}
			else
			{
				a[r-1].len-=max(a[l].len,a[r].len)-min(a[l].len,a[r].len);
			}
		}
	}
	cout<<ans;
	return 0;
}




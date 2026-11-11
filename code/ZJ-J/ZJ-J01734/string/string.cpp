#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{int l,r;char c;};
int n;
int x,cnt,xg;
node s[300100];
int lrf(int x)
{
	int mid,l=1,r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(s[mid].l<=x&&s[mid].r>=x)return mid;
		if(s[mid].l>x)r=mid-1;
		else l=mid+1;
	}
	return -1;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	getchar();
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&x);
		getchar();
		scanf("%c",&s[i].c);
		getchar();
		s[i].l=cnt+1;
		s[i].r=cnt+x;
		cnt=s[i].r;
	}
	int len=lrf(cnt/2);
	int fd,sl,sr;
	int lin,sy;
	for(int i=1;i<len;++i)
	{
		sr=lrf(cnt+1-s[i].l);
		sl=lrf(cnt+1-s[i].r);
		if(sl==sr)
		{
			if(s[sl].c!=s[i].c)
			{
				xg+=s[i].r-s[i].l+1;
			}
		}
		else
		{
			lin=sl+1;
			if(s[sl].c!=s[i].c)
			{
				xg+=s[sl].r-(cnt+1-s[i].r)+1;
			}
			for(;lin<sr;++lin)
			{
				if(s[lin].c!=s[i].c)
				{
					xg+=s[lin].r-s[lin].l+1;
				}
			}
			if(s[sr].c!=s[i].c)
			{
				xg+=(cnt+1-s[i].l)-s[sr].l+1;
			}
		}
	}
	sr=lrf(cnt+1-s[len].l);
	sl=lrf(cnt+1-cnt/2);
	if(sl==sr)
	{
		if(s[sl].c!=s[len].c)
		{
			xg+=cnt/2-s[len].l+1;
		}
	}
	else
	{
		lin=sl+1;
		if(s[sl].c!=s[len].c)
		{
			xg+=(cnt+1-s[sl].r)-s[len].r+1;
		}
		for(;lin<sr;++lin)
		{
			if(s[lin].c!=s[len].c)
			{
				xg+=s[lin].r-s[lin].l+1;
			}
		}
		if(s[sr].c!=s[len].c)
		{
			xg+=(cnt+1-s[len].l)-s[sr].l+1;
		}
	}
	cout<<xg;
	return 0;
}

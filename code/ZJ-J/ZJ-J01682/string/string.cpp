#include<bits/stdc++.h>
using namespace std;
struct node
{
	int len;
	char op;
};
const int maxn=2e5+10;
node a[maxn];
struct block
{
	long long l,r;
	char op;
};
int n;
long long cnt;
long long nw;
vector<block>fr,ed;
bool flag;
int edid;
long long yulen;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].len>>a[i].op;
		cnt+=a[i].len;
	}
	if(cnt%2)
	{
		for (int i=1;i<=n;i++)
		{
			if(nw+a[i].len>=cnt/2+1)
			{
				a[i].len++;
				break;
			}
			nw+=a[i].len;
		}
		cnt++;
		nw=0;
	}
	for (int i=1;i<=n;i++)
	{
		if(nw+a[i].len>=cnt/2&&!flag)
		{
			int sum=cnt/2-nw;
			fr.push_back({nw+1,sum+nw,a[i].op});
			ed.push_back({cnt/2+1,nw+a[i].len,a[i].op});
			flag=1;
			nw+=a[i].len;
			continue;
		}
		if(nw+a[i].len>=cnt/2&&flag)
		{
			ed.push_back({nw+1,nw+a[i].len,a[i].op});
			nw+=a[i].len;
			continue;
		}
		if(nw+a[i].len<cnt/2)
		{
			fr.push_back({nw+1,nw+a[i].len,a[i].op});
			nw+=a[i].len;
			continue;
		}
	}
	reverse(ed.begin(),ed.end());
	yulen=ed[0].r-ed[0].l+1;
	for (block x:fr)
	{
		int nl=x.l;
		int nr=x.r;
		long long nwlen=x.r-x.l+1;
		while(nwlen>=yulen)
		{
			nwlen-=yulen;
			if(ed[edid].op!=x.op)
				ans+=yulen;
			edid++;
			yulen=ed[edid].r-ed[edid].l+1;
		}
		if(nwlen)
		{
			if(ed[edid].op!=x.op)
				ans+=nwlen;
			yulen-=nwlen;
		}
	}
	cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
#define ll unsigned int
#define i128 __int128
#define F first
#define S second

const int LO=31;
const int MN=2e5+10;
int n,m,top=1;
ll ans;

struct node
{
	ll ls,rs;
	ll cnt;
}t[MN*LO];

int dfs(int s,int b)
{
	if(s)
	{
		if(b>=0)
		{
			if(ans&(1u<<b))
			{
				return dfs(t[s].rs,b-1);
			}else
			{
				return dfs(t[s].ls,b-1)+dfs(t[s].rs,b-1);
			}
		}else
		{
			return t[s].cnt;
		}
	}
	return 0;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	t[1]={0,0,0};
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		int s=1;
		for(int i=LO-1;i>=0;i--)
		{
			if(x&(1u<<i))
			{
				if(t[s].rs==0)
				{
					t[s].rs=++top;
					t[top]={0,0,0};
				}
				s=t[s].rs;
				t[s].cnt++;
			}else
			{
				if(t[s].ls==0)
				{
					t[s].ls=++top;
					t[top]={0,0,0};
				}
				s=t[s].ls;
				t[s].cnt++;
			}
		}
	}
	for(int b=LO-1;b>=0;b--)
	{
		ans|=1u<<b;
		if(dfs(1,LO-1)<m)
		{
			ans^=1u<<b;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,n,d,x[2000010],e[2000010],nxt[2000010],last[2000010],s[2000010],ansl;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>T;
	while(T--)
	{
		ansl=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			e[i]=0;
			s[i]=0;
			last[i]=i;
			nxt[i]=i;
		}
		for(int i=1;i<=n;i++)
		{
			ll l=i+1,r=n,mid,ans=i;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(x[mid]-x[i]<=d)
				{
					ans=max(ans,mid);
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			nxt[i]=ans;
			if(i<last[ans])
			{
				last[ans]=i;
			}
		}
		for(int i=2;i<=n;i++)
		{
			if(nxt[i-1]==i)
			{
				e[i]=e[last[i]]+1;
			}
		}
		for(int i=n-1;i>=1;i--)
		{
			if(last[i+1]==i)
			{
				s[i]=s[nxt[i]]+1;
			}
		}
		for(int i=1;i<n;i++)
		{
			if(nxt[i]>i+1 && nxt[nxt[i]-1]>nxt[i] && nxt[nxt[i]-2]<=nxt[i])
			{
				ansl+=(e[i]+1)*(s[nxt[nxt[i]-1]]+1);
			}
		}
		cout<<ansl<<'\n';
	}
	return 0;
}

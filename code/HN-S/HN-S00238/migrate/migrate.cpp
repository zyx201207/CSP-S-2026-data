#include<bits/stdc++.h>
using namespace std;
int c,n;
long long d,x[2000006],k,t[2000006],f[2000006];
queue<int> q;
void solve()
{
	cin>>n>>d;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(c==11||c==12)
	{
		int k=d/(x[2]-x[1]);
		if(k==0||k==1)
		{
			cout<<"0\n";
		}
		else cout<<max(n-k-k+1,0)<<"\n";
		return;
	}
	if(c==13||c==14)
	{
		if(t[1]-f[n]!=1)
		{
			cout<<"0\n";
			return;
		}
		int x,y;
		for(int i=1;i<=n;i++)
		{
			if(t[i]!=t[1])
			{
				x=i-1;
				break;
			}
		}
		for(int i=n;i>=1;i--)
		{
			if(f[i]!=f[n])
			{
				y=i+1;
				break;
			}
		}
		cout<<1ll*x*(n-y+1)<<"\n";
		return;
	}
	for(int i=1;i<=n;i++)
	{
		while(q.size())
		{
			if(x[i]-x[q.front()]<=d)
			{
				t[q.front()]=i;
				break;
			}
			else
			{
				q.pop();
			}
		}
		q.push(i);
	}
	while(q.size())
	{
		t[q.front()]=n;
		q.pop();
	}
	for(int i=n;i>=1;i--)
	{
		while(q.size())
		{
			if(x[q.front()]-x[i]<=d)
			{
				f[q.front()]=i;
				break;
			}
			else
			{
				q.pop();
			}
		}
		q.push(i);
	}
	while(q.size())
	{
		f[q.front()]=1;
		q.pop();
	}
	for(int i=2;i<n-1;i++)
	{
		int l,r,ll=0,rr=0;
		for(l=i-1;l>=1;l--)
		{
			if(t[l]!=i+1)
			{
				l++;
				break;
			}
		}
		if(l==0)l++;
		for(r=i+2;r<=n;r++)
		{
			if(f[r]!=i)
			{
				r--;
				break;
			}
		}
		if(r==n+1)r--;
		if(l==i||r==i+1)continue;
		ll=i-l;
		rr=r-i-1;
//		cout<<i<<" "<<l<<" "<<r<<"\n";
		while(1)
		{
			if(f[l]==l)break;
			if(f[l]!=1)
			{
				l=f[l];
				ll++;
			}
			else if(t[1]==l)
			{
				ll++;
				break;
			}
			else break;
		}
		while(1)
		{
			if(t[r]==r)break;
			if(t[r]!=n)
			{
				r=t[r];
				rr++;
			}
			else if(f[n]==r)
			{
				rr++;
				break;
			}
			else break;
		}
		ans+=1ll*ll*rr;
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

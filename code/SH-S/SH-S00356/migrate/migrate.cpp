#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d;
ll c;
ll t;
ll df[1010];
queue<ll> q;
ll x[5010];
ll ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<=n;++i)
		{
			memset(df,0x3f,sizeof(df));
			while(!q.empty()) q.pop();
			q.push(i);
			for(int j=i+1;j<=n;++j)
			{
				while(!q.empty()&&x[j]-x[q.front()]>=d) q.pop();
				if(q.empty()) break;
				df[j]=df[q.front()]+1;
			}
			ll rt=0;
			for(int j=i+1;j<n;++j)
			{
				if(df[j]==df[j+1]) rt++;
			}
			if(rt==1) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

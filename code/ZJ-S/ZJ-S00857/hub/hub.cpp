//rp++ please
#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> mp[1000006];
bool f[1000005];
queue<long long> del;
long long rt = 1;
void init()
{
	rt = 1;
	memset(f,0,sizeof f);
	while(!del.empty()) del.pop();
	for(long long i=1;i<=n;i++) mp[i].clear();
}
void AAA(long long u,long long fa)
{
//	cerr<<u<<" "<<fa<<"\n";
	long long cnt = 0;
	for(auto v:mp[u]) 
	{
		if(!f[v]) cnt++;
	}
	if(cnt==1) del.push(u);
	for(auto v:mp[u])
	{
		if(v==fa||f[v]) continue;
//		cerr<<v<<" ";
		AAA(v,u);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//  don't forget long long!
// 	don't forget cheak cpp!
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long t,q;
	cin>>t>>q;
	while(q--)
	{
		cin>>n>>m;
		init();
		long long u,v;
		for(long long i=1;i<n;i++)
		{
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);	
		}
		if(m==n)
		{
			cout<<"0\n";
			continue;
		}
//		AAA(n,0);
		AAA(rt,0);
		long long ans = 0;
		while(n-del.size()>=m)
		{
			n -= del.size();
			ans++;
			if(n==m) break;
			while(!del.empty())
			{
				f[del.front()] = 1;
				del.pop();
			}
			while(rt<=n&&f[rt]) rt++;
			if(rt>n) break;
			AAA(rt,0);
		}
		if(m==n)
		{
			cout<<ans<<"\n";
			continue;
		}
		long long t = (n-m+1)/2;
		cout<<max(t,ans)<<"\n";
	}
	return 0;
}
/*
mayde 4-8 or 0
100+[70,80]+[0,16]+[0,8] [170,204] 1=?
all right please
I try best...
18:18
I notice T4's time is 3.00s
*/

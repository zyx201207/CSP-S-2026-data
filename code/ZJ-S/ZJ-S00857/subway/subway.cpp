#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
struct NODE
{
	long long x,y;
	bool operator <(const NODE t) const
	{
		return x<t.x;
	}
};
long long c,n,m,d,q;
long long w[500005];
long long L[505];
vector<NODE> sub[505];
long long mp[505][505];
void floyd()
{
	for(long long k=1;k<=m;k++)
	{
		for(long long i=1;i<=m;i++)
		{
			if(i==k) continue;
			for(long long j=1;j<=m;j++)
			{
				if(i==j||j==k) continue;
				mp[i][j] = min(mp[i][j],mp[i][k]+mp[j][k]);
			}
		}
	}
}
long long fd(long long x,long long i)
{
	long long l = 0;
	long long r = L[i]-1;
	while(l<r)
	{
		long long mid = l+r+1>>1;
//		cout<<x<<" "<<i<<" "<<mid<<"\n";
		if(sub[i][mid].x==x) return mid;
		if(sub[i][mid].x>x) r = mid-1;
		else l = mid;
	}
	if(sub[i][l].x==x) return l;
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//  don't forget long long!
// 	don't forget cheak cpp!
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(long long i=1;i<=n;i++) cin>>w[i];
	long long x,y;
	for(long long i=1;i<=m;i++)
	{
		cin>>L[i];
		for(long long j=1;j<=L[i];j++)
		{
			cin>>x>>y;
			sub[i].push_back({x,y});
		}
		sort(sub[i].begin(),sub[i].end());
	}
	memset(mp,0x3f,sizeof mp);
	for(long long i=1;i<=m;i++)
	{
		for(long long j=i+1;j<=m;j++)
		{
			long long ans = inf;
			long long t1 = 0;
			long long t2 = 0;
			while(t1<L[i]&&t2<L[j])
			{
				long long x = sub[i][t1].x;
				long long y = sub[j][t2].x;
				if(x==y)
				{
					ans = min(ans,sub[i][t1].y+sub[j][t2].y);
					t1++;
					t2++;
				}
				else if(x<y) t1++;
				else t2++;
			}
			mp[i][j] = mp[j][i] = ans;
//			cout<<ans<<"\n";
		}
	}
	floyd();
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++) cout<<mp[i][j]<<" ";cout<<"\n";
//	}
	for(long long i=1;i<=m;i++) mp[i][i] = 0;
	while(q--)
	{
		cin>>x>>y;
		long long f1 = 0;
		long long f2 = 0;
		long long ans = inf;
		for(long long i=1;i<=m;i++)
		{
			f1 = fd(x,i);
			if(f1==-1) continue;
			for(long long j=1;j<=m;j++)
			{
				if(mp[i][j]>=inf) continue;
				f2 = fd(y,j);
				if(f2==-1) continue;
				ans = min(ans,w[x]+w[y]+mp[i][j]+sub[i][f1].y+sub[j][f2].y);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
i hope least AC 1-21 72-80per
*/

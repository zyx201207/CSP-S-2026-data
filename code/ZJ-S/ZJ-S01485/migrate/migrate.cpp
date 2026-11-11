#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
long long c,t;
long long n,d;
long long x[2000002];
long long flag[2000002];
long long ans;
bool vis[2000002];
vector<long long> vec[2000002];
long long cnt[2000002];
long long dist[200][10001];
long long box[2000002];
void dfs(long long id)
{
	flag[id]++;
	if(vis[id])
	{
		return;
	}
	vis[id]=1;
	for(auto t:vec[id])
	{
		dist[t][++cnt[t]]=dist[id][cnt[t]-1]+x[t]-x[id];
		dfs(t);
	}
}
void solve()
{
	ans=0;
	cin>>n>>d;
	for(long long i=1;i<=n;i++)
	{
		vec[i].clear();
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i];
		for(long long j=i-1;j>=1;j--)
		{
			if(x[i]-x[j]<=d)
			{
				vec[j].push_back(i);
			}
		}
	}
	for(long long i=1;i<n;i++)
	{
		long long minn=LLONG_MAX;
		for(long long j=1;j<=n;j++)
		{
			vis[j]=0,flag[j]=0,dist[j][0]=0;
		}
		memset(box,0,sizeof box);
		dfs(i);
		for(long long j=i+1;j<=n;j++)
		{
			for(long long k=1;k<=cnt[j];k++)
			{
				box[dist[j][k]]++;
				minn=min(minn,dist[j][k]);
			}
			if(box[minn]==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
//	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cout<<"Mirage"<<endl;
//	cout<<"zai dian huan de huang zhou,xun zhen shi de lv zhou"<<endl;
//	cout<<"miao xiao de ru fu you ye wang zhe yu zhou"<<endl;
//	cout<<"Can it be real"<<endl;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
tui yi dao ji shi 16 fen zhong
cha bu duo jiu zhe yang ba
ba wen jian jian cha yi xia jiu zou la
Bye~zai jian!
*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
//#define p(x) cerr<<"debug:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;
/*====================*/
const int N=2e6+10;
const int INF=1e18;
/*====================*/
int c,n,d;
int x[N]; 
/*====================*/
void solve()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		int k=d/(x[2]-x[1]);
		if(k<=1)
		{
			cout<<0<<endl;
			continue;
		}
//		if(k==2)
//		{
//			if(n<4)
//			{
//				cout<<0<<endl;
//				continue;
//			}
//			if(n%2==0)
//			{
//				cout<<n*n/4-n+1<<endl;
//				continue;
//			}
//			else
//			{
//				int sum=n*n/4-n+1;
//				sum+=(n-3)/2;
//				cout<<sum<<endl;
//				continue;
//			}
//		}
//		else
//		{
			k*=2;
			int sum=max(n-k+1,0ll);
			cout<<sum<<endl;;
			continue;
//		}
	}
	exit(0);
}
/*====================*/
int cnt=0,maxx=INF;
void dfs(int step,int end_,int tot)
{
	if(cnt>2)return;
	if(tot==maxx)return;
	if(x[end_]-x[step]<=d)
	{
		if(maxx>tot+1)
		{
			maxx=tot+1;
			cnt=1;
		}
		else if(maxx==tot+1)cnt++;
		return;
	}
	int now=step;
	while(x[step+1]-x[now]<=d)step++;
	while(step>now&&cnt<=2)dfs(step--,end_,tot+1);
}
void solve1()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt=0,maxx=INF;
			dfs(i,j,0);
			if(cnt==2)ans++;
		}
	}
	cout<<ans<<endl;
}
/*====================*/
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c;
	cin>>c;
	if(c==11||c==12)solve();
	int T;
	cin>>T;
	while(T--)solve1();
	return 0;
}


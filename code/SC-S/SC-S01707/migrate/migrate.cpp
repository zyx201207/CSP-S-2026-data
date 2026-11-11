#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=5001;
int n,d,C,t,a[2000060],cnt[mxn][mxn],dis[mxn][mxn],sum[mxn][mxn];
void solve()
{
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>d;
	int ans=0;
	for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) cnt[i][j]=sum[i][j]=a[i]=0,dis[i][j]=LLONG_MAX;
	for (int i=1;i<=n;i++) cin>>a[i],dis[i][i]=0;
	for (int i=1;i<=n;i++)
	{
		int mxL=i,mxR=i;
		cnt[i][i]=1;
		sum[i][i]=1;
		for (int j=i+1;j<=n;j++)
		{
			while (a[j]-a[mxL]>d) mxL++;
			if (mxL==j) break;
			mxR=max(mxR,mxL);
			while (dis[i][mxR+1]==dis[i][mxL]) mxR++;
			dis[i][j]=dis[i][mxL]+1;
			cnt[i][j]=sum[i][mxR]-sum[i][mxL-1];
			if (cnt[i][j]==2) ans++;
			sum[i][j]=sum[i][j-1]+cnt[i][j];
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>C>>t;
	while (t--) solve();
	return 0;
}
//TLE/RE-40pts
/*
高二小登，倒数第二舞
A会做
B会做
C不是很会做
D不想做
=========
那个 xxx 毁了我的省队梦。
whk还是区，OI还是区，我该在哪里停留？我问我自己。
========
感觉前面有唐错，但无所谓了
18:15准备重测大样例
感冒考试，有点爽
========
开干
收工
========
感觉这次一等线大概180pts上下，不是很难好像
或者直接230?
红红青紫
*/

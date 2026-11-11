#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],pre[500005];
int cmp(int x,int y)
{
	return x<y;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=-1,lst=m,lstcnt=1,lstplace=n-1;
	for(int i=n;i>=1;i--)
	{
		int cnt=lstcnt,t=lst,now=lstplace;
		while(1)
		{
			if(now<=0)
			{
				lst=t+(cnt-1)*(a[i]-a[i-1]);
				lstcnt=cnt-1;
				lstplace=now;
				break;
			}
			if(t<a[i]-a[now])
			{
				lst=t+(cnt-1)*(a[i]-a[i-1]);
				lstcnt=cnt-1;
				lstplace=now;
				break;
			}
			cnt++;
			t-=a[i]-a[now];
			now--;
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}

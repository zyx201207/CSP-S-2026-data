#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],l[100005],last[200005],cnt[200005];
int ans[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m ;
	bool t1=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] ;
		last[i]=l[a[i]];
		l[a[i]]=i;
		if(a[i]<a[i-1]) t1=0;
	}
	if(t1)
	{
		for(int i=1;i<=m;i++)
		{
			cout << l[i] << ' ' ;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int now=0;//Æ«ÒÆÁ¿ 
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++)
		{
			if( cnt[last[j]-now]==a[j] && last[j]-now < j-now )
			{
				now+=(j-last[j]);
			}
			else if( cnt[last[j]]==a[j] && last[j] < j-now )
			{
				now+=j-last[j]-now;
			}
			cnt[j-now]=a[j];
			cout << now << endl ;
		}
		for(int j=i;j<=n-now;j++)
		{
			ans[cnt[j]]++ ;
			cout << cnt[j] << ' ' ;
		}
		cout << endl ;
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << ' ' ;
	}
	return 0;
}

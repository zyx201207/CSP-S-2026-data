/*
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
*/
//#include<bits\stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt[40],vis[200010],a[200010][40],ans;
int main()
{
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	ans=(1<<30)-1;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=29;j>=0;j--)
		{
			if((x>>j)&1)
			{
				a[i][j]=1;
				cnt[j]++;
			}
		}
	}
	for(int i=29;i>=0;i--)
	{
		int count=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]&&!vis[j])
			{
				count++;
			}
		}
		if(count<m)
		{
			ans^=(1<<i);
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			if(!a[j][i]&&!vis[j])
			{
				vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
//start: 9:04
//end: 9:16
/*
wo xiang jin mi huo xing wei da shang
luogu uid=1861592
*/
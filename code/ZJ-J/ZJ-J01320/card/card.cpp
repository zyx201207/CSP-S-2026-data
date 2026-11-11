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
int n,m,a[500010],siz[500010],fat[500010],fa[500010],nxt[500010],b[300010],ans[300010];
vector<int> e[500010];
void dfs2(int now)
{
	for(int i=0;i<e[now].size();i++)
	{
		dfs2(e[now][i]);
		siz[now]+=siz[e[now][i]];
	}
	ans[a[now]]+=siz[now];
}
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fat[i]=i;
		siz[i]=1;
		cin>>a[i];
		nxt[b[a[i]]]=i;
		b[a[i]]=i;
	}
	fat[n+1]=n+1;
	siz[n+1]=1;
	for(int i=n;i>=1;i--)
	{
		if(!nxt[i])
		{
			e[fat[i+1]].push_back(i);
			fa[i]=fat[i+1];
		}
		else
		{
			fat[i]=fat[nxt[i]];
			siz[fat[i]]++;
			fa[i]=nxt[i]+1;
		}
	}
	dfs2(n+1);
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
//start: 9:18
//end: 11:11
/*
wo xiang jin mi huo xing wei da shang
luogu uid=1861592
*/
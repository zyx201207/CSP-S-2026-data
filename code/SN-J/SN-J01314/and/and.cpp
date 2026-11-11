#include<bits/stdc++.h>
using namespace std;
int n, m;long long maxnn=-1;
bool vis[25];
long long a[200005];

//65ptrs

void dfs(long long w, int g)
{
	if(g==m) 
	{
		maxnn=max(maxnn, w);
//		cout<<w<<endl;
	}
	
	else
	{
		for(int i = 1; i<=n; i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				dfs(w&a[i], g+1);
				vis[i]=0;
			}
		}
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0)
	
	cin>>n>>m;
	long long maxn=-1, lie, lei;
	for(int i = 1; i<=n; i++) 
	{
		cin>>a[i];
		if(i==1) lie=a[i];
		else lie&=a[i];
		lei|=a[i];
		maxn=max(maxn, a[i]);
	}
	if(m==1) 
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		cout<<lie;
		return 0;
	}
	if(m==2) 
	{
		maxn=-1;
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				if(i==j) continue;
				maxn=max(maxn, a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(maxn<4)
	{
		sort(a+1, a+1+n);
		if(a[n-m+1]==0) 
		{
			cout<<0;
			return 0;
		}
		if(a[n-m+1]==3) 
		{
			cout<<3;
			return 0;
		}
		if(a[n-m+1]==2) 
		{
			cout<<2;
			return 0;
		}
		if(a[n-m+1]==1) 
		{
			int ty[4]={0, 0, 0, 0};
			for(int i = n; i>=1; i--)
			{
				ty[a[i]]++;
			}
			
			if(ty[1]+ty[3] >= m) cout<<1;
			else cout<<0;
			return 0;
		}
	}
	if(n<=20)
	{
		memset(vis, 0, sizeof(vis));
		dfs(lei, 0);
		cout<<maxnn;
		return 0;
	}
	sort(a+1, a+1+n);
	cout<<a[n-m+1];
	return 0;
}


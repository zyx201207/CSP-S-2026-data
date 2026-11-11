#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool v[200005];
int dfs(int k,bool v[],int maxx)
{
	v[k]=1;
	int maxt=0,cnt=0,l;
	for(int i=1;i<=n;i++)
	{
		if(v[i]) cnt++;
		l=a[i];
	}
	if(cnt==1) return l;
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0&&i!=k)
		{
			dfs(i,v,maxx&a[i]);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<dfs(1,v,0);
	return 0;
}


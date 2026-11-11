#include<bits/stdc++.h>
using namespace std;
int a[200010],n,m,b[200010],t[200010],l[200010];
bool g[200010];
void dfs(int k,int s)
{
	if(k>n) return;
	if(s>n)
	{
		for(int j=1;j<=s;j++) t[j]=0,b[j]=0;
		for(int i=1;i<s;i++) a[i]=a[i+1];
		n--;
		s=1;
		k++;
	}
	if(b[a[s]])
	{
		for(int j=1;j<=s;j++) t[j]=0,l[j]=0,b[j]=0,g[j]=0;
		b[a[s]]=1;
		t[1]=a[s];
		if(!g[a[s]])
		{
			 l[a[s]]=s;g[a[s]]=1;
		 }
		dfs(k,s+1);
	}
	else if(!b[a[s]])
	{
		b[a[s]]=1;
		if(!g[a[s]])
		{
			l[a[s]]=s;g[a[s]]=1;
		}
		t[s]=a[s];
		dfs(k,s+1);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	dfs(1,1);
	for(i=1;i<=m;i++) cout<<l[i]<<" ";
	return 0;
}

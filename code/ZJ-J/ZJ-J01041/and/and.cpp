#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int n,m;
int ans;
void dfs(int x,int step,int cnt){
	if(step==m)
	{
		ans=max(ans,cnt);
		return;
	} 
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,step+1,(cnt&a[i]));
	}
}
bool cmp(int w,int k)
{
	return w>k;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
	} 
	if(m==n)
	{
		int ct=a[1];
		for(int i=2;i<=n;i++) ct=(ct&a[i]);
		cout<<ct;
		return 0;
	}
	if(maxx<=4)
	{
		int v[5]={0};
		for(int i=1;i<=n;i++) v[a[i]]++;
		for(int i=maxx;i>=1;i--)
		{
			if(v[i]>=m)
			{
				cout<<i;
				return 0;
			}
		}
		if(v[2]+v[3]>=m) cout<<2;
		else if(v[1]+v[3]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n>2000)
	{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	for(int i=1;i<=n;i++) dfs(i,1,a[i]);
	cout<<ans;
	return 0;
}
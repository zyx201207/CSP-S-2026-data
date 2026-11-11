#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool vis[200010];
int ans[200010];
int n,m;
int answer=-1,now_ans;
int temp;
void dfs(int k)
{
	if(k==m+1)
	{
		now_ans=ans[1]&ans[2];
		for(int i=3;i<=m;i++)
		{
			now_ans=now_ans&ans[i];
		}
		answer=max(answer,now_ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			ans[k]=a[i];
			dfs(k+1);
			vis[i]=false;
			ans[k]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	/*
	if(n==1)
	{
		cout<<a[1];
	}
	else if(n==2)
	{
		temp=a[1]&a[2];
		cout<<temp;
	}
	else if(n==3)
	{
		if(m==3)
		{
			temp=a[1]&a[2]&a[3];
			cout<<temp;
		}
		else if(m==2)
		{
			cout<<max(a[2]&a[3],(a[1]&a[2],a[1]&a[3]));
		}
	}
	else
	{
	*/
		dfs(1);
		cout<<answer;
	//}
	return 0;
}

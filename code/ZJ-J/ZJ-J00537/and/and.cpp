#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int mx;
int lowbit(int x)
{
	return x&-x; 
}
void dfs(int now,int tmp,int sum)
{
	if(tmp==m)
	{
		mx=max(mx,sum);
		return ;
	}
	for(int i=now+1;i<=n;i++) dfs(i,tmp+1,sum&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n]; 
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		vector<int> s(n+10);
		s[1]=a[1];
		int ans=a[2];
		for(int i=3;i<=n;i++) ans=ans&a[i];
		for(int i=2;i<=n;i++)
		{
			s[i]=s[i-1]&a[i];
			int num=s[i-1];
			for(int j=i+1;j<=n;j++) num=num&a[j];
			ans=max(ans,num);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) dfs(i,1,a[i]);
	cout<<mx;
	return 0;
}
/*
5 4
31 15 20 25 21
3
*/
//		int y=a[n];
//		while(1)
//		{
//			if(y-lowbit(y)==0) break;
//			y-=lowbit(y);
//		}
//		y=(y<<1)-1;
//		for(int i=1;i<=n;i++)
//		{
//			int x=a[i];
//			a[i]=y;
//			while(x!=0)
//			{
//				int z=lowbit(x);
//				a[i]-=z;
//				x-=z;
//			}
//		}
//		int ans=0;
//		for(int i=1;i<=n;i++) ans=max(ans,num|a[i]);
//		cout<<ans;

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N];
int ans[M];
int mp[M];
int op=1;
map<int,int> ma;
void slove(int x)
{
	stack<int> st;
	for(int i=x;i<=n;i++)
	{
		if(mp[a[i]]==0) mp[a[i]]=1,st.push(a[i]);
		else
		{
			int now=st.top();
			while(now!=a[i])
			{
				st.pop();
				mp[now]=0;
				now=st.top();
			}
			mp[a[i]]=1;
		}
	}
	while(!st.empty())
	{
		int now=st.top();
		--mp[now];
		++ans[now];
		st.pop();
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		++ma[a[i]];
		if(op==1&&a[i-1]>a[i]) op=0;
	}
//	if(m==2) ËÆºõ²»ÐÐ 
//	{
//		int w[]={0,0,0};
//		for(int i=n;i>=1;i--)
//		{
//			if(w[1]!=0||w[2]!=0) break;
//			w[i]=max(w[i],i);
//		}
//		cout<<
//	}
	if(ma.size()==m&&op==1)
	{
		int tmp=0;
		for(int i=1;i<=m;i++) tmp+=ma[i],cout<<tmp<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++) slove(i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
5 3
1 1 2 3 3
2 3 5
*/

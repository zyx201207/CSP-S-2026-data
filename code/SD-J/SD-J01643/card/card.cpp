#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
const int INF=0x3f3f3f3f;
using namespace std;
int n,m;
int ans[N];
vector<int> a;
int find(int x,int b[],int cnt)
{
	for(int i=0;i<cnt;i++)
	{
		if(b[i]==x)
		{
			return i; 
		}
	}
	return -1;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		int b[N];
		for(int j=i-1;j<=n;j++)
		{
			int l=find(a[j],b,cnt);
			if(l==-1)
			{
				b[cnt++]=a[j];
			}
			else
			{
				cnt=l;
				b[cnt++]=a[j];
			}
		}
		for(int i=0;i<cnt;i++)
		{
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/

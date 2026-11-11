#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=3e5+5,M=3e5+5;
int a[N],t[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x=q.front();
			if(x==a[j])
			{
				while(!q.empty()) 
				{
					q.pop();
				}
			}
			q.push(a[j]);
		}
		while(!q.empty()) 
		{
			int num=q.front();
			t[num]++;
			q.pop();
			
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
} 

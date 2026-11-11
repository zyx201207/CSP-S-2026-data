#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
int a[N],b[M];
map<int,int>vis;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	deque<int>q;
	for(int i=1;i<=n;i++)
	{
		q.clear();
		vis.clear();
		vis[0]=1;
		for(int j=i;j<=n;j++)
		{
			q.push_back(a[j]);
			vis[a[j]]++;
			if(vis[a[j]]>1)
			{
				do
				{
					vis[q.front()]=0;
					q.pop_front();
				}
				while(q.front()!=a[j]&&q.size());
				vis[a[j]]=0;
			}
		}
//		cout<<i<<"\n";
		while(!q.empty())b[q.front()]++,q.pop_front();//cout<<q.front()<<" ",
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

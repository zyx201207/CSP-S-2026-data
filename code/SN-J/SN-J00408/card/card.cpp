#include<bits/stdc++.h>
using ll=long long;
using namespace std;

const int maxn=5e5+10;

int n,m;
int a[maxn],tong[maxn],h,bj[maxn];
deque<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	h=1;
	for(int i=n;i>=1;i--)
	{
		if(!bj[a[i]])
			q.push_back(a[i]),bj[a[i]]=1;
		else
		{
			while(q.back()!=a[i]&&!q.empty())bj[q.back()]=0,q.pop_back();	
		}
		for(int i=1;i<=m;i++)
			if(bj[i])
			{
				tong[i]++;
//				cout<<i<<" ";
			}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
	return 0;
}

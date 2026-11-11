#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int n;
int sum=0;
int ans=0;
deque<pair<int,char> > q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		q.push_back({x,y});
	}
	while(q.size()>1)
	{
		pair<int,char> l=q.front();
		q.pop_front();
//		cout<<l.first<<" "<<l.second<<"\n";
		while(!q.empty())
		{
			pair<int,char> r=q.back();
			q.pop_back();
//			cout<<r.first<<" "<<r.second<<"\n";
			if(l.first>r.first)
			{
				l.first-=r.first;
				if(l.second!=r.second)
				{
					ans+=r.first;
				}
			}
			else
			{
				r.first-=l.first;
				if(l.second!=r.second)
				{
					ans+=l.first;
				}
				q.push_back(r);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

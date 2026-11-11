#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int shu;
	char zhi;	
};
deque<node> d;
int n,cnt,g;
char c;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cnt>>c;
		d.push_back({cnt,c});
	}
	while(d.size())
	{
		node u=d.front();
		node q=d.back();
		d.pop_front();
		if(d.size())
		d.pop_back();
		if(u.shu==q.shu&&u.zhi==q.zhi)
		continue;
		else
		{
			if(u.shu>q.shu)
			{
				if(u.zhi!=q.zhi)
				{
					g+=q.shu;
				}
				d.push_front({u.shu-q.shu,u.zhi});
			}
			else
			{
				if(u.zhi!=q.zhi)
				{
					g+=u.shu;
				}
				d.push_back({q.shu-u.shu,q.zhi});
			}
		}
	}
	cout<<g;
}

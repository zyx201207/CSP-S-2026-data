#include<bits/stdc++.h>
using namespace std;
struct node
{
	char name;
	long long time;
};
long long ans=0;
deque<node> q;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long T;
	cin>>T;
	string s;
	long long sum=0;
	for(int i=1;i<=T;i++)
	{
		long long num;
		char c;
		cin>>num>>c;
		sum+=num;
		q.push_back({c,num});
	}
	while(q.size()>1)
	{
		node a=q.front();
		q.pop_front();
		node b=q.back();
		q.pop_back();
		if(a.name!=b.name)
		{
			if(a.time>b.time)
			{
				ans+=b.time;
				a.time-=b.time;
				q.push_front(a);
			}
			else if(a.time==b.time)
			{
				ans+=a.time;
			}
			else if(a.time<b.time)
			{
				ans+=a.time;
				b.time-=a.time;
				q.push_back(b);
			}
		}
		else
		{
			if(a.time>b.time)
			{
				a.time-=b.time;
				q.push_front(a);
			}
			else if(a.time<b.time)
			{
				b.time-=a.time;
				q.push_back(b);
			}
		}
	}
	cout<<ans;
	return 0;
}

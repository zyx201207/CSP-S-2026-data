#include<bits/stdc++.h>
using namespace std;
struct note
{
	int n;
	char c;
};
deque<note> dq;
int main()
{
	ios::sync_with_stdio(false);//cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int n;
		char c;
		cin>>n>>c;
		dq.push_back({n,c});
	}
	queue<note> q1;
	queue<note> q2;
	q1.push(dq.front());
	q2.push(dq.back());
	dq.pop_front();
	dq.pop_back();
	long long ans=0;
	while(!dq.empty())
	{
		if(q1.size()==0)
		{
			q1.push(dq.front());
			dq.pop_front();
		}
		if(q2.size()==0)
		{
			q2.push(dq.back());
			dq.pop_back();
		}
		note a=q1.front(),b=q2.front();
		if(a.c==b.c)
		{
			if(a.n<b.n)
			{
				q1.pop();
				q2.front().n-=a.n;
			}
			else if(a.n>b.n)
			{
				q2.pop();
				q1.front().n-=b.n;
			}
			else
			{
				q1.pop();
				q2.pop();
			}
		}
		else
		{
			if(a.n<b.n)
			{
				ans+=a.n;
				q2.front().n-=a.n;
				q1.pop();
			}
			else if(a.n>b.n)
			{
				ans+=b.n;
				q1.front().n-=b.n;
				q2.pop();
			}
			else
			{
				ans+=a.n;
				q1.pop();
				q2.pop();
			}
		}
	}
	cout<<ans;
	return 0;
} 

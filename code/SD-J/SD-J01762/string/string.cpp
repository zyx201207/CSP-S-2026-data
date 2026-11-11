#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a;
	char c;
};

deque<node> q;
long long ans;
int main()
{
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		node x;
		cin>>x.a >>x.c ;
		q.push_back(x);
	}
	while(!q.empty())
	{
		if(q.front().c!=q.back().c)
		{
			if(q.front().a>q.back().a)
			{
				ans+=q.back().a;
				q.pop_back();
				q.front().a-=q.back().a;
			}
			else if(q.front().a<q.back().a)
			{
				ans+=q.front().a;
				q.pop_front();
				q.back().a-=q.front().a;
			}
			else if(q.front().a==q.back().a)
			{
				ans+=q.back().a;
				q.pop_front();
				q.pop_back();
			}
		}
		else
		{
			if(q.front().a>q.back().a)
			{
				q.pop_back();
				q.front().a-=q.back().a;
			}
			else if(q.front().a<q.back().a)
			{
				q.pop_front();
				q.back().a-=q.front().a;
			}
			else if(q.front().a==q.back().a)
			{
				q.pop_front();
				q.pop_back();
			}
		}
		if(q.size()==1 )
		{
			q.pop_back();
		}
	}
	
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
________________________

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

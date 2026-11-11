#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll sum,cd;
queue<char> q;
stack<char> s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int a;
		char b;
		cin>>a>>b;
		cd+=a;
		for(int j=0;j<a;++j)
		{
			q.push(b);
			s.push(b);
		}
	}
	for(int i=0;i<cd/2;++i)
	{
		if(q.front()!=s.top())
		{
			++sum;
			q.pop();
			s.pop();
		}
	}
	cout<<sum;
	return 0;
} 

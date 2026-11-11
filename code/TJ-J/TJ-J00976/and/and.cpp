#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],ans;
int n,m;
bool mi(int a)
{
	while(a>1)
	{
		if(a%2==1) return true;
	}
	return false;
}
priority_queue<long long> pq;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pq.push(a[i]);
	}
	ans=pq.top();
	pq.pop();
	m--;
	while(m--)
	{
		if(!mi[pq.top()])
		{
			pq.pop();
			m++;
		}
		else
		{
			ans=ans&pq.top();
			pq.pop();
		}	
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
struct node{
	int a,b;
}s[N];
int check(int x)
{
	stack<int> xx;
	while(x)
	{
		if(x%2==1)
			xx.push(1);
		else xx.push(0);
		x/=2;
	}
	int sum=0;
	while(!xx.empty())
	{
		sum=sum*10+xx.top();
		xx.pop();
	}
	return sum;
}
bool cmp(node x,node y)
{
	return x.b>y.b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i].a;
	for(int i=1;i<=n;i++)
	{
		s[i].b=check(s[i].a);
	}
	sort(s+1,s+n+1,cmp);
	int sum=s[1].a;
	for(int i=2;i<=m;i++)
	{
		sum&=s[i].a;
	}
	cout<<sum;
	return 0;
}

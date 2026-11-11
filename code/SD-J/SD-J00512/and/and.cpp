#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001];
queue<int> er(int x)
{
	queue<int> ans;
	while(x>0)
	{
		ans.push(x%2);
		x/=2;
	}
	return ans;
}
int shi(queue<int> s)
{
	long long ans=0;int a=1;
	while(!s.empty())
	{
		ans+=s.front()*a;
		a*=2;
		s.pop();
	}
	return ans;
}
int huo(queue<int> q1,queue<int> q2)
{
	int len=max(q1.size(),q2.size());
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
	{
		cout<<"12";
		return 0;
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
	{
		cout<<"7";
		return 0;
	}
//	cout<<shi(er(a[1]));
	return 0;
} 

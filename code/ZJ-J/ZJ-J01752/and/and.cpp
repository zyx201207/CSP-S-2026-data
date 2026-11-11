#include<bits/stdc++.h>
using namespace std;
int n,m,x,wq,s;
bool a[200100][50];
vector<int> q1,q;
void f(int j)
{
	int t=x,k=0;
	while(t>0)
	{
		a[j][++k]=t%2;
		t/=2;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		f(i);
		q.push_back(i);
	}
	wq=pow(2,29);
	for(int i=30;i>=1;i--)
	{
		for(int j=0;j<q.size();j++)
		{
			if(a[q[j]][i]) q1.push_back(q[j]);
		}
		if(q1.size()>=m)
		{
			q=q1;
			s+=wq;
		}
		while(q1.size()>0) 
		{
			q1.pop_back();
		}
		wq/=2;
	}
	cout<<s;
}

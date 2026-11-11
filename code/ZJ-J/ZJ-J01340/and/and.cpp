#include<bits/stdc++.h>
using namespace std;
struct Node
{
	long long x;
	vector<int> y;
}a[201000];
long long n,m,b[45],c,d[45],s;
bool f[201000];
//bool cmp(Node a,Node b)
//{
//	return a.x<b.x;
//}
void dfs(long long x)
{
	for(int i=1;i<=n;i++)
	{
		if(f[i]) continue;
		if((a[i].x/b[x])%2==0)
		{
			f[i]=1;
			continue;
		}
		for(int j=0;j<a[i].y.size();j++)
		{
			d[a[i].y[j]]++;
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	b[0]=1;
	for(int i=1;i<=35;i++) b[i]=b[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		c=a[i].x;
		for(int j=0;c;j++)
		{
			if(c%2==1) 
			{
				a[i].y.push_back(j);
				d[j]++;
			}
			c/=2;
		}
	}
//	sort(a+1,a+1+n,cmp);
	for(int i=32;i>=0;i--)
	{
		if(d[i]>=m)
		{
			for(int j=32;j>=0;j--) d[j]=0;
			s+=b[i];
			dfs(i);
		}
	}
	cout<<s;
	return 0;
}
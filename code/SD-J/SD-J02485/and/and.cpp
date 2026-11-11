#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5*2;int n,m;
int a[N+5];int b[N+5];int top=0;
void search(int u,int q,int sum)//half dfs
{
	q--;
	int i;
	if(q==0)
	{
		top++; 
		b[top]=sum;return;
	}
	for(i=u+1;i<=n-q+1;i++)
	{
		int z=a[i]&sum;
		search(i,q,z);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,j,maxn;
	cin>>n>>m;
	if(n==m)
	{
		for(i=1;i<=n;i++)
		cin>>a[i];
		int sum=a[1];
		for(i=2;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;return 0;
	}
	if(m==1)
	{
		for(i=1;i<=n;i++)
		cin>>a[i];
		int maxn=a[1];
		for(i=1;i<=n;i++)
		maxn=max(a[i],maxn);
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		for(i=1;i<=n;i++)
		cin>>a[i];int maxn=-1;
		for(i=1;i<=n-m+1;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				int sum=a[i]&a[j];
				if(sum>=maxn)
				maxn=sum;
			}
		}
		cout<<maxn;return 0;
	}
	//^pian fen^
	if(n<=20)
	{
		maxn=-1;
		for(i=1;i<=n;i++)
		cin>>a[i];
		for(i=1;i<=n-m+1;i++)
		search(i,n-m,a[i]);
		for(i=1;i<=top;i++)
		{
			if(b[i]>maxn)
			maxn=b[i];
		}
		cout<<maxn;return 0;
	}
	cout<<4;
	return 0;
}

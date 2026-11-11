#include<bits/stdc++.h>
using namespace std;
struct Node{
	int en;
	int ch;
	int h;
}a[500009];
int n,m,ans,sum,cc;
bool cmp(Node x,Node y)
{
	return x.en<y.en;
}
int c(int x,int y)
{
	return a[y-1].h-a[x-1].h;
}
bool de()
{
	int j=a[2].en-a[1].en;
	for(int i=2;i<n;i++)
		if(a[i+1].en-a[i].en!=j)
			return false;
	cc=j;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++)
		cin >>a[i].en;
	sort(a,a+n+1,cmp);
	if(de())
	{
		int k=0;
		while(m>0)
		{
			k++;
			m-=k*cc;
		}
		cout <<k<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		a[i].ch=a[i+1].en-a[i].en;
		a[i].h=a[i-1].h+a[i].ch;
	}
	a[n].h=a[n-1].h;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=c(k,j);
			}
			if(sum<=m)
				ans=max(ans,j-i+1);
		}
	}		
	cout <<ans<<endl;
	return 0;
}


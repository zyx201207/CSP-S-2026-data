#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool b[200005];
int c[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n,p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=m;
	for(int i=30;i>=0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j])continue;
			int h=0;
			if((1<<i)&a[j])
			{
				p++;
				h++;
				c[p]=a[j];
				b[j]=true;
			}
			m-=h;
			if(m<=0)break;
		}
		if(m<=0)break;
	}
	sort(c+1,c+1+n,cmp);
	int k=c[1];
	for(int i=1;i<=t;i++)
	{
		k&=c[i];
	}
	cout<<k;
	return 0;
}

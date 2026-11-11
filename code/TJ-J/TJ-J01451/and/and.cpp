#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int v;
	int p;
	int x;
}a[200009];
int h=-1e9;
int w;
bool cmp(node x,node y)
{
	if(x.v==y.v)
	{
		return x.p>y.p;
	}
	return x.v<y.v;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p;
		h=max(h,a[i].p);
		w=i;
	}
		while(h>0)
		{
			if(h%2==0)
			{
				a[w].v++;
			}
			else a[w].x++;
			h/=2;
		}
	long long ans=a[w].x+a[w].v;
	long long k;	
	for(int i=1;i<=n;i++)
	{
		k=a[i].p;
		while(k>0)
		{
			if(k%2==0)
			{
				a[i].v++;
			}
			else a[i].x++;
			k/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=w)
		{
		a[i].v+=(ans-a[i].v-a[i].x);
	}
	}
	sort(a+1,a+n+1,cmp);
	int q=a[1].p;
	for(int i=2;i<=m;i++)
	{
		q&=a[i].p;
	}
	cout<<q;
	return 0;
 } 

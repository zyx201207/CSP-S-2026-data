#include<bits/stdc++.h>
#define F10 ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int a[1145144];
int n,m,mn;
struct abc{
	int ab;
	int bc;
};
int lrs(abc x,abc y,int z)
{
	if(z==2)
	{
		return x.ab&y.ab;
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(i!=x.bc&&i!=y.bc)
		{
			a[mn]=x.ab&y.ab;
			abc X={a[mn],mn};
			abc Y={a[i],i};
			mn++;
			k=max(k,lrs(X,Y,z-1));
		}
	}
	return k;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	F10
	std::cin>>n>>m;
	mn=m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int Max=0;
	if(m==2)
	{
		for(int i=0;i<n-1;i++)
		{
			int k=0; 
			for(int j=i+1;j<n;j++)
			{
				k=max(k,a[i]&a[j]);
			}
			Max=max(Max,k);
		}
		std::cout<<Max;
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		int k=0;
		for(int j=i+1;j<n;j++)
		{
			abc I={a[i],i},J={a[j],j};
			int s=lrs(I,J,m);
			k=max(k,s);
		}
		Max=max(k,Max);
	}
	std::cout<<Max;
	return 0;
}

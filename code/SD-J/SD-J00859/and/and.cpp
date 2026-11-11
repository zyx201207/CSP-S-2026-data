#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int n,m;
int q(int k,int i,int l)
{
	int max=0;
	if(i==n-1)
	{
		return l;
	}
	i++;
	for(;i<n;i++)
	{
		int t;
		if(k>1&&k<m)
		{
			l=l&a[i];
			t=q(k+1,i,l);
		}
		else if(m==k)
		{
			t=a[i]&l;
		}
		else
		{
			t=q(k+1,i,a[i]);
		}
		if(t>max)
		{
			max=t;
		}
	}
	return max;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	t=q(1,0,0);
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 

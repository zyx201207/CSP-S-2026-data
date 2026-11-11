#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[200005];
	int n,m,a1;
	int maxn=-1;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a1;
		a[i]=a1;
	}
	sort(a,a+n);
	int s,s1;
	for(int i=0;i<n;i++)
	{
		s=a[i];
		if(i+m<=n)
		{
			for(int j=1;j<m;j++)
			{
				s1=a[i+j];
				s=s&s1;			
			}
			maxn=max(maxn,s);			
		}			
	}
	cout<<maxn;
	return 0;
}
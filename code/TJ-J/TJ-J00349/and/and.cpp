#include<bits/stdc++.h>
using namespace std;
long long a[200001];
long long s[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c=0,l=0,y=1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int mx=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mx<a[j])
			{
				mx=a[j];
				l=j;
			}	
		}
		s[c]=mx;
		mx=0;
		c++;
		a[l]=0;
	}
	y=s[0];
	for(int i=1;i<m;i++)
		y&=s[i];
	cout<<y;
	return 0;
 } 

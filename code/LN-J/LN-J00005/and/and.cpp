#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((a[i]&a[j])>mx)
			{
				mx=a[i]&a[j];
			}
		}
	}
	cout<<mx;
	return 0;
}

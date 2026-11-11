#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
		{
			int h=a[i];
			int l=a[i-1];
			a[i]=l;
			a[i-1]=h;
		}
	}
	
	cout<<a[m];
}

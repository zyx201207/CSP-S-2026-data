#include <bits/stdc++.h>
using namespace std;                           
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[200005];
	int b[200005];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	int j=1;
	for(int i=m;i>=1;i--)
	{
		b[j]=a[i];
		j++;
	}
	cout<<b[n];
	return 0;
}
  	
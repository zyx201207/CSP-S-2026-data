#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005],b=0,c=1,n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	b=a[0];
	m--;
	while(m--)
	{
		b=b&a[c];
		c++;
	}
	cout<<b;
	return 0;
}

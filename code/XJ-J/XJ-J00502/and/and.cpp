#include<bits/stdc++.h>
using namespace std;
long long int a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
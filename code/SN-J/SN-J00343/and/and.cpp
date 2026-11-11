#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],ans;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	cin>>n,m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	printf("%d",a[1]);
}

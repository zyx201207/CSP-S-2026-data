#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],flag[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<>());
	int b;
	for(int i = 2;i <= m;i++)
	{
		if(i==2)b=a[i-1]&a[i];
		else b=b&a[i];
	}
	cout<<b;
	return 0;
}

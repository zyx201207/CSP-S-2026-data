#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int num=0;
	int ma;
	for(int i=1;i<=n;i++)
	{
		num=a[i]&a[i+1];
		ma=max(ma,num);
	}
	cout<<ma;
	return 0;
}

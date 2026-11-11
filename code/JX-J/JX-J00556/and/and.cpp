#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma=0;
int an(int i,int j)
{
	if(i&j>ma) return i&j;
	else return ma;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			ma=max((a[i]&a[j]),ma);
		}
	}
	cout<<ma;
    return 0;
}
















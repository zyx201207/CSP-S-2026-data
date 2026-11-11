#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ret;
bool cmp(int s,int b)
{
	return s>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ret=a[1];
	for(int i=2;i<=m;i++)
	{
		ret&=a[i];
	}
	cout<<ret;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
const long long MAXN=2e5+5;
int a[MAXN];
int ma[MAXN];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp); 
	int k=1;
	for(int i=1;i<=m;i++)
	{
		ma[k++]=a[i];
	}
	
	ans=ma[1];
	for(int i=2;i<k;i++)
	{
		ans&=ma[i];
	}
	cout<<ans;
	return 0;
}

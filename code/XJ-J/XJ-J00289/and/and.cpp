#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int a[N];
int awy(int a,int b)
{
	return a&b;
}
bool cmp(int a,int b)
{
	return a>b;
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
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=awy(ans,a[i]);
	}
	cout<<ans;
}

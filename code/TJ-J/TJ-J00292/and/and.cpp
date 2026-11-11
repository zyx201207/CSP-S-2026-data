#include<bits/stdc++.h>
using namespace std;
int a[200001];
bool ex(int a,int b)
{
	return a>=b;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","r",stdout);
	int n,m,maxa=-1,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,ex);
	for(int i=1;i<=n-m+1;i++)
	{
		b=a[i];
		for(int j=i+1;j<i+m;j++)
		{
			b&=a[j];
		}
		maxa=max(b,maxa);
	}
	cout<<maxa;
	return 0; 
}

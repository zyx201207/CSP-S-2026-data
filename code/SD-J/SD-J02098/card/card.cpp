#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[500005],t[300005],ans[300005];
bool x[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(x[a[i]])
		{
			for(int j=t[a[i]];j<i;j++)
			{
				ans[a[j]]+=i-t[a[j]];
				t[a[j]]=j,x[a[j]]=!x[a[j]];
				a[j]=0;
			}
		}
		else
		{
			t[a[i]]=i,x[a[i]]=1;
		}
		t[0]=0;
	}
	for(int i=1;i<=k;i++)
	{
		if(x[a[i]])
		{
			ans[a[i]]+=n-t[a[i]];
		}
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}

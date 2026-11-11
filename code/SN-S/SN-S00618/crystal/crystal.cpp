#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int max1=-1;
	for(int i=1;i<=n;i++)
	{
		int sum=1;
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]<=m)
			{
				sum++;
				m-=(a[i]-a[j]);
			}
		}
		max1=max(max1,sum);
	}
	cout<<max1;
	return 0;
}

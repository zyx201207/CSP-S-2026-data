#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,cnt=0;
	int a[100005];
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1]||a[i]+1==a[i+1]&&cnt<m;
		{
			cnt++
			a[i+1]=a[i]+a[i+1];
		}
	}
	cout<<cnt;
	return 0;
}

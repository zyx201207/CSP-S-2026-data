#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=0,m=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	int k=(n+1)/2;
	int d=a[k];
	for(int i=1;i<=m;i++)
	{
		while(a[k-1]<a[k]&&m!=0)
		{
			if(a[k-1]<a[k])
			a[k-1]++;
			}
			k--;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[k]){
			ans++;
		}
		else
		continue;
	}
	cout<<ans;
	return 0;
}

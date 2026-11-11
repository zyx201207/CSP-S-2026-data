#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i])
		{
			ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[100005],c[100005],ans,s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		s=a[i];
	}
	a[s+1]=n;
	for(int i=s;i>=1;i--)
	{
		if(i<=m) c[i]=n-cnt[i+1];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}

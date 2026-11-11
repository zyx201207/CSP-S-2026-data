//SN-S00478 朱振华 西安市远东第二中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
int shuliang()
{
	int maxx=0,shu[100000]={0};
	for(int i=1;i<=n;i++)
	{
		shu[a[i]]++;		
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,shu[i]);
	}

	return maxx;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	int x=1;
	while(m--)
	{
		a[1]++;
		sort(a,a+n+1);
		b[x]=shuliang();
		x++;
	}
	int ans;
	for(int i=1;i<=n+1;i++)
	{
		ans=max(ans,b[i]);
	}
	cout<<ans;
	return 0;
}

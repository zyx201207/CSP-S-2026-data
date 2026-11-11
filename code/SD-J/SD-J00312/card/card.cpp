#include<bits/stdc++.h>
using namespace std;
const int maxN=5e5+10;
int n,m;
int a[maxN],ans[maxN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		cout<<1;
		return 0;
	}
	if(m==2)
	{
		int t=0,p=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) t++;
			if(a[i]==2) p=i;
		}
		cout<<t<<' '<<p;
		return 0;
	}
	memset(ans,-1,sizeof ans);
	for(int i=n;i>=1;i--)
	{
		if(ans[a[i]]==-1) ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
} 

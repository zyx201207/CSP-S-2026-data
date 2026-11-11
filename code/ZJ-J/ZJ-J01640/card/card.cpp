#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500001],a[500001],tng[500001];
void play(int round)
{
	int tt[500001];
	memcpy(tt,tng,sizeof(tng));
	for(int i=round;i<=n;i++)
	{
		if(tt[a[i]]!=1)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==a[i])
				{
					tt[a[i]]--;
					i=j-1;
					break;
				}
			}
		}
		else ans[a[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tng[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		play(i);
		tng[a[i]]--;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
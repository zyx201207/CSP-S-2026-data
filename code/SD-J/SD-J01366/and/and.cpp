#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans=0,p=1<<30;
bool vis[200001];
int main()
{	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(p)
	{	int s=0;
		for(int i=1;i<=n;i++)
			if(!vis[i] && a[i]>=p)
				s++;
		if(s>=m)
		{	for(int i=1;i<=n;i++)
			{	if(vis[i])
					continue;
				if(a[i]>=p)
					a[i]-=p;
				else
					vis[i]=1;
			}
			ans+=p;
		}
		for(int i=1;i<=n;i++)
			if(a[i]>=p)
				a[i]-=p;
		p>>=1;
	}
	cout<<ans;
	return 0;
}

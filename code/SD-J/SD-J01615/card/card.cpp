#include<bits/stdc++.h>
using namespace std;
int n,m,x,top;
int a[500086],q[500086],ans[500086];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int k=1; k<=n; k++)
	{
		for(int i=k; i<=n; i++)
		{
			for(int j=1; j<=top; j++) 
			{
				if(a[i]==q[j]) top=j-1;
			}
			q[++top]=a[i];
		}
		for(int i=1; i<=top; i++)
		{
			ans[q[i]]++;
		}
		memset(q,0,sizeof(q));
	}
	for(int i=1; i<=m; i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

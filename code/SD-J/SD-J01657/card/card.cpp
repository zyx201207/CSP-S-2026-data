#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],f[300005],st[500005],top,ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n*m<1e8)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(f[a[j]]) while(st[top]!=a[j]){f[st[top--]]=0;}
				else st[++top]=a[j];
				f[a[j]]=1;
			}
			for(int j=1;j<=top;j++) ans[st[j]]++;
			for(int j=1;j<=m;j++) f[j]=0;
			top=0;
		}
	}
	else
	{
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

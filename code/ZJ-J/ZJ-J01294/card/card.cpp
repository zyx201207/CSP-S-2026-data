#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],x[300005],top,ans[300005];//pai,youx,zuih,
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		top=0;
		memset(x,0,sizeof(x));
		for(int j=i;j<=n;j++)
		{
			if(x[a[j]]==0||x[a[j]]>top)
			{
				x[a[j]]=++top;
				b[top]=a[j];
			}
			else
				top=x[a[j]];
			//cout<<top;
		}
		for(int j=1;j<=top;j++)
			ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0; 
}
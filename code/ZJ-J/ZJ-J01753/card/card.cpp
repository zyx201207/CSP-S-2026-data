#include<bits/stdc++.h>
using namespace std;
int q,n,m,a[200010],t[200010],ans[200010],f[200010],biao[200010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++) t[j]=0,f[t[j]]=0,biao[a[j]]=0;
		q=0;
		for(int j=i;j<=n;j++)
		
			if(f[a[j]]==0) t[++q]=a[j],f[a[j]]=1,biao[a[j]]=q;
			else
			{
				for(int k=biao[a[j]]+1;k<=q;k++)
				{
					f[t[k]]=0,t[k]=0,biao[t[k]]=0;
				}
				q=biao[a[j]];
			}
			for(int j=1;j<=q;j++) ans[t[j]]++;
		}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
//Trick||Treat!                          

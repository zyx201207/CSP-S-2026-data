#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int q=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		q=0;
		for(int j=i;j<=n;j++)
		{	
			q++;
			b[q]=a[j];
			for(int l=q;l>=1;l--)
			{
				if(a[j]==b[l])
				{
					for(int z=l;z<=q;z++)
					{
						b[z]=0;
					}
					q=l;
					b[q]=a[j];
				}
				
			}
		}
		for(int w=1;w<=q;w++)
		{
			c[b[w]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}

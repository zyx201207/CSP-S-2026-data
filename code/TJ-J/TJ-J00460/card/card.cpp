#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,m;
int a[500005],b[500005],t[300005],ans[300005];
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) b[j]=0;
		for(int j=1;j<=m;j++) t[j]=0;
		for(int j=i;j<=n;j++)
		{
			t[a[j]]++;
			b[j]=a[j];
			if(t[a[j]]>1&&a[j]!=0) 
			{
				for(int k=i;k<j;k++)
				{
					if(b[k]==a[j])
					{
						for(int l=k;l<j;l++) 
						{
							t[b[l]]--;
							b[l]=0;
						}
					}
				}
			}
	    }
	    for(int i=1;i<=m;i++) if(t[i]>0) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

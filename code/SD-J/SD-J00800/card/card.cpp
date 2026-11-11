#include<bits/stdc++.h>
using namespace std;
int n,m,a[600006],qian[600006],wei2[600006],zhi,ans[600006],ting[600006],iii,lian[600006],wei[600005];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		lian[i]=i+1;
	}
	for(int i=n;i>=1;i--)
	{
		wei2[a[i]]++;
		if(wei2[a[i]]==1) wei[a[i]]=i;
		if(wei2[a[i]]>=2)
		{
			//cout<<i<<" "<<a[i]<<endl;
			for(int j=i+1;j<=wei[a[i]];)
			{
				if(j<=wei[a[i]]-1&&a[j]!=a[i])
				{
				    qian[j]=max(i,qian[j]);
			    }
			    else
			    {
			    	lian[i]=j;
				}
				j=lian[j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		ting[i]=n+1;
	}
	for(int i=n;i>=1;i--)
	{
		if(i<ting[a[i]])
		{
		    ans[a[i]]=ans[a[i]]+i-qian[i];
		    ting[a[i]]=qian[i];
		    //cout<<i<<" "<<a[i]<<" "<<qian[i]<<endl;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
} 


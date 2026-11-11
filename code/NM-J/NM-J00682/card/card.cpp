#include<bits/stdc++.h>
using namespace std;
int n,a[500001],b[500001],m,c[500001],len=0,ans=0,sum[300001];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    for(int i=1;i<=n;i++)
         {
         	memset(c,0,sizeof(c));
         	memset(b,0,sizeof(b));
           	for(int j=i;j<=n;j++)
           	    {
           	    	if(b[a[j]]==0)
           	    	       {
           	    	       	len++;
           	    	       	c[len]=a[j];
           	    	       	ans+=a[j];
           	    	       	b[a[j]]=len;
							  }
					else 
					  {
					  	for (int k=1+b[a[j]];k<=len;k++)
					  	{
						    ans=ans-c[k];
						    b[c[k]]=0; 
						} 
					  	  len=b[a[j]];
					  }
				   }
			for(int j=1;j<=len;j++)
			   sum[c[j]]++;
		 }
		for(int i=1;i<=m;i++)
		 cout<<sum[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 


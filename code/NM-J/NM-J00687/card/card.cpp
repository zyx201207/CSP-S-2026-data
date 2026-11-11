#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],tong[300005],syg[300005],he[300005];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 }
	 
	for(int i=1;i<=n;i++)//一共n局 
	 {
	    memset(tong,0,sizeof(tong));
	    memset(syg,0,sizeof(syg));
	    
	 	for(int j=i;j<=n;j++)//每局 
	 	 {
	 	 	if(tong[a[j]]==0) {tong[a[j]]++;syg[a[j]]=j;}
	 	 	            else for(int k=syg[a[j]]+1;k<j;k++)
	 	 	                   tong[a[k]]--;
	 	 	
		  }
	    for(int j=1;j<=m;j++)
	    he[j]+=tong[j];
	 }
	for(int i=1;i<=m;i++)
	 cout<<he[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 

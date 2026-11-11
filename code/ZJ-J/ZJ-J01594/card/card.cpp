#include<bits/stdc++.h>
using namespace std;    
int n,m,a[510000],f[510000],mp[310000],q[310000],b[510000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
 	sort(b+1,b+1+n);
 	bool flag=0;
 	for(int i=1;i<=n;i++) 
 	{
	 	if(b[i]!=a[i])
	 	{
			flag=1;
			break;	 	
		}
	}
	if(flag==0)
	{
		for(int i=1;i<=m;i++) cout<<1<<" ";
		return 0;
	}
 	for(int i=1;i<=n;i++)
 	{
 		int w=0;
 		memset(f,0,sizeof(f));
 		memset(q,0,sizeof(q));
 		for(int j=i;j<=n;j++)
 		{
 			if(f[a[j]]==0) f[a[j]]=1,q[++w]=a[j];
 			 else
 			 { 
 			 	for(int k=w;k>=1;k--) 
 				{
 					if(q[k]!=a[j]) f[q[k]]=0;
 					 else
 					 {
 					 	w=k;
 					 	break;
				     }
				} 
			 }
			
		}  
		for(int j=1;j<=w;j++)  mp[q[j]]++; 
	}
	for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

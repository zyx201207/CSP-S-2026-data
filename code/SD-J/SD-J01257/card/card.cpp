#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
   long long n,m;
   cin>>n>>m;
   long long a[n+1],ans[m+1],mn[n+1];
   for(long long i=1;i<=n;i++) cin>>a[i];
   for(long long i=1;i<=m;i++){
   	ans[i]=0;
   }
   bool ok[n+1];
   for(long long i=1;i<=n;i++){
   	long long j=1;
   	
   	for(long long jb=1;jb<=n;jb++){
   		ok[jb]=0; 
   		mn[jb]=-1;
	   } 
   	//น้มใ 
   	for(long long j2=i;j2<=n;j2++){
   		if(ok[a[j2]]==1){
   		while(mn[j]!=a[j2]){
   			j--;
   			ok[mn[j+1]]=0;
   			mn[j+1]=-1;
		   }	
		}else{
			mn[j]=a[j2];
			ok[a[j2]]=1;		
		}
		  j++;  
	   }
	//for(int z=1;z<=j;z++) cout<<mn[z]<<" ";
	//cout<<endl;
	for(long long jb=1;jb<=m;jb++){
	if(jb<=m)
	ans[jb]+=ok[jb];	
	}   
   }
   for(long long i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
 } 

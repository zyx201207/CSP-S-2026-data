#include <bits/stdc++.h>
using nampspace std;
int main{
freopen("train.in","r",stdin);
freopen("train.out","w",stdout);
int c,t;
cin>>c>>t;
int nk;
cin>>n>>k;
int minn; 
cin>>minn;
int maxn;
cin>>maxn;
for(int i=1;i<=n;i++)
{for(int j=0;j<=i;j++)
 { if(n[i]<=2&&(n-1)*2==n)
   {n[i]==minn; 
   	
	   }else if(n[i]<=2&&(n+1)*2<n) {
	   
	    n[i]=minn;
	   }
	   else if(n[i]<=2&&(n-1)*2>n)	
 	    {
 	    	n[i]=maxn;
		 }
 	    else{
 	     break;	
 	    }
 	   
	}	
}

while(n>0)
{ if(n[i]<=2&&(n-1)*2&&n[i])==minn
    cout<<n[i];
	
	}	
    else if(n[i]<=2&&(n+1)*2<n)	
	{
		cout<<n[i]£» 
	}break; 
   else{
   	break; 
   } 


cout<<n[i];
return 0;
}

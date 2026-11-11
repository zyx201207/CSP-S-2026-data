#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
bool sv[N];
int cnt[101][N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=1;
	for(int i=1;i<=30;i++)ans*=2;
	ans-=1;
     int n,m;
	 cin>>n>>m;
	 int a[n+1];
	 for(int i=1;i<=n;i++)cin>>a[i];
	 int jk=n,l=0;
	 if(m==1)
	 {
	 	int kk=0;
	 	for(int i=1;i<=n;i++)kk=max(kk,a[i]);
	 	cout<<kk;
	 	return 0;
	 }
	 if(m==n)
    {
    	int ui=0;
      for(int i=1;i<=n;i++)
	  {
	   ui=ui&a[i];	
	  }  	
	  cout<<ui;
	  return 0;
	}
	int sum=0;
	 
	   for(int i=1;i<=n;i++)
	   {
	   	int  k=a[i];
	    int mm=0;
	   	while(k)
	   	{
	   	    cnt[mm][i]=k%2;
	   	    mm++;
	   		k/=2;
		}
		sum=max(sum,mm);
	}
	   sum--;
	   for(int i=sum;i>=0;i--)
	   {
	   	int v1=0;
	   	for(int j=1;j<=n;j++)
	   	  {
          if(cnt[i][j]==1&&sv[j]==0)v1++;	   		
		  }
		  if(v1<m)continue;
		  if(v1==m)
		  {
		  //	long long ans=1111111111111111;
		  	for(int j=1;j<=n;j++)
		  	{
		  		if(cnt[i][j]==1&&sv[j]==0)ans=ans&a[j];
			}
			cout<<ans;
			return 0;
		  }
		  if(v1>m)
		  {
		  	for(int j=1;j<=n;j++)
		  	{
		  		if(!cnt[i][j])sv[j]=1;
			}
		  }
	   }
	   //cout<<"0";
	   long long k=0;
	   for(int i=1;i<=n;i++)
	   {
	   	if(k==m)break;
	       if(!sv[i])
	       {
	       		   ans=ans&a[i];
	       		   k++;
	          //  cout<<ans<<endl;
		   }
	     
	      
	   }
	   cout<<ans;
	return 0;
}
//
//
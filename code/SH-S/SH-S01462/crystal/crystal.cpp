#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int c=0;
int j=0;
int b;
int e=0;
int cct=0;
int cnt=0; 
int ctt=0;
long long ct[10000000];
long long a[1000000];

//void quicksort(int*a);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
int d =m;
for(int i=0;i<n;i++)
	 cin>>a[i];
sort(a+1,a+n);
if(m==0||n==1)
	  ans=n;
else
	for(int i=1;i<=n;i++)
      {
	  if (i==a[i])
      ctt++;}
    if(ctt==n)
      {
	  e=(a[n]+a[1])*n/2;
      if(m>=e)
      ans=1;
      else{
	  
	  for(int i=0;i<n;i++){
	 
	    if(d>=0)
		{
		 d=d-i-1;
		 cct++;
	    }
		} 
	  ans=n-cct;}
}else  
	for(int i=0;i<n;i++)
	{
	  if(j>1)
	   ct[j-1]=a[j]-a[j-1];
	  if(j>2)
	  {
	  if(ct[j-1]==ct[j-2])
	    cnt++;
		}
	  j++;}
	 if(cnt==n-2)
	  {
	  b=ct[1];
	  for(int i=0;i<n;i++)
	    if(d>=0)
		{
		 d=d-i-b;
		 cct++;
	    }
	  ans=n-cct;}  
	/*for(int i=0;i<n;i++)
	  if (i>0)
	   if(a[i]=a[i-1])
	   c=c+1;
	if(c=n)
	
	*/
	cout<<ans;
	return 0;
}


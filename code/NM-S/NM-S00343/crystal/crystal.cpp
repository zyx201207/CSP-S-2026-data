#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans1,maxx=-1,b[500005],anssj,l,r,mid,sum1,len,maxs=-10000010,minn=10000020;
long long check(int bz){
	ans1=0;
	anssj=0;
	sum1=0;
	len=0;
	l=1;
	r=n;
 	while(l<=r)
 	 {
 	   mid=(l+r)/2;
 	   if(a[mid]>bz) 
		{
			r=mid-1;
			ans1=mid;
		 } 	
	   else l=mid+1;
	  }
	for(int i=ans1-1;i>=1;i--)
	  {
	  	if(sum1+(bz-a[i])<=m)
	  	 {
	  	 	sum1=sum1+(bz-a[i]);
	  	 	anssj++;
		   }
		else break;
	  }
	  return anssj;
 }
int main()
 {
 	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	   		cin>>a[i];
 	sort(a+1,a+1+n);
    for(int i=a[n];i>a[1];i--)
    {
    	maxx=max(maxx,check(i));
    	if(len-1==maxx) break;
	}
	cout<<maxx; 
    fclose(stdin);
 	fclose(stdout);
 	return 0;
  } 

#include<bits/stdc++.h>
using namespace std;
int c,w,t;
int sh,cnt;
int ans,s,m;
int j;
long long ct[10000000];
long long n[10000000],d[1000000];
long long x[1000000];
//void quicksort(int*x);
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
	cin>>n[i]>>d[i];
	s=n[i];
	m=0;
	for(int I=1;I<=n[i];I++)
	cin>>x[I];
    sort(x+1,x+n[i]);
	
	for(int l=1;l<=n[l];l++){
	

	for(int t=1;t<=n[l];t++)
	{
	  if(j>1)
	   {
	   ct[j-1]=x[j]-x[j-1];}
	 if(j>2)
	  {
	  if(ct[j-1]==ct[j-2])
	    cnt++;}
	  j++;}
	if(cnt==n[l]-2)
	{
	
	 if(d[i]>=x[s]-x[m])
	 {
	 cout<<0;	
	 }}
	 else
	 {
	 	w=ct[1];
	 sh=d[i]/w;
	 ans=n[l]-sh-1;
	 }
	}cout<<ans;
	}
	
	  
}

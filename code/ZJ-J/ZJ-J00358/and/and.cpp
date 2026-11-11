#include<bits/stdc++.h>
using namespace std;
long long n,b[200010],a,s,m,k=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1,maxn=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		maxn=max(maxn,b[i]);
	 } 
	 if(m==1)
	 {
	 	cout<<maxn;
	 	return 0;
	  }
	  if(m==n)
	  {
	  	for(int i=1;i<=n;i++)
	  	{
	  		k=(k&b[i]); 
		  }
		  cout<<k;
		  return 0;
	  }
	  sort(b+1,b+n+1);
	  cout<<b[n-m+1];
	return 0;
}

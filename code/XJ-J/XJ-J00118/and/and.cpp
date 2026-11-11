#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  int m,n,a[34],b=0,c,d[67];
  cin>>n>>m; 
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i];
  }
  for(int i=1;i<=n;i++)
  {  d[i]=a[i];
    if(b<d[i]^m)
    {
    	b=d[i]^m;
    	c=a[i];
	}
  }
  cout<<c<<endl;
}

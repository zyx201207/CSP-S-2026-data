#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[2000];
int main()
{
  freopen("and.in","r",stdin)
  freopen("and.out","w",tsdout)
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<=n;i++)
  {
    if(a[i]>a[i-1])
    {
      x=a[i];
    }
  }
  cout<<x;
}

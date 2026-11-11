#include <iostream>
using namespace std;
int a[1000000001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int sum=0;
    for(int i=n;i>=1;i--)
    {
    sum=0;
      for(int j=i-1;j>=1;j--)
      {
         sum=sum+(a[i]-a[j]);
      }
      if(m<sum)
      break;
    }
    cout<<sum;
    return 0;
}

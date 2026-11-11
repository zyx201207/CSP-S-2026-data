#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,k=0;
    long long b[100000],c;
    cin>>a>>c;
    for(int i=1;i<=a;i++)
        cin>>b[i];
    for(int i=1;i<=a-1;i++)
    {
      if(b[i+1]<b[i])
        k=1;
    }
    if(k==1)
    {
      for(int i=1;i<=a;i++)
      {
          for(int j=1;j<=a-1;j++)
          {
              if(b[j]>b[j+1])
              {
                int t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
              }
          }
      }
    }
    long long d=0;
    int e=0;
    for(int i=1;d<=c;i++)
    {
      d+=(b[i+1]-b[i])*i;
      e++;
      if(i==a)
        break;
    }
    cout<<e;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return 0;
}

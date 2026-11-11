#include<bits/stdc++.h>
using namespace std;

int n,x,lll;
struct s
{
    long long sl;
    char zm;
}; s a[10000000001];

int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>n;

  for(int i=1;i<=n;i++){
        cin>>a[i].sl>>a[i].zm;
  }
  if(n==1){
    cout<<0;
  }
  else{
      string abc[1000000000000];
      for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].sl;j++)
            abc[j+x]=a[i].zm;
        x+=a[i].sl;
      }
      for(int i=1;i<=x/2;i++){
        if(abc[i]!=abc[x-i+1]) lll++;
      }
      cout<<lll;
  }
 return 0;
}


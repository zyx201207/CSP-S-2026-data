#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001]={};
int x[300001]={};
int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  int m,n;
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
  }
  for(int i=2;i<=n;i++){
    for(int j=i+1;j<=n;j++){
    if(a[i]!=a[j]){
        for(int l=1;l<i;l++) x[a[l]]+=l-i;
    }
  }
  }
  x[a[n]]=n;
  for(int i=1;i<=m;i++) cout<<x[i]<<' ';
  return 0;
}

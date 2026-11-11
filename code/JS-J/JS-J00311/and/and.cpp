#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000001]={};
int main()
{
   long long x=0,y;
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  for(int i=1;i<=n;i++)cin>>a[i];
  if(m==1){
    for(int i=1;i<=n;i++) x=max(x,a[i]);
  }
  else if(m==2){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            y=a[i]&&a[j];
            x=max(x,y);
        }
    }
  }
    else if(m==n){
        x=a[1];
        for(int i=1;i<=n;i++) x=x&&a[i];
    }

    cout<<x;
  return 0;
}



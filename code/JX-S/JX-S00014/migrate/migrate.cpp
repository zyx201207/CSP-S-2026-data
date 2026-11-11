#include<bits/stdc++.h>
using namespace std;
long long a[2000004]={};
int main(){
   freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
  int c,t;
  long long n,d,e=100;
  cin>>c>>t;
  while(t--){
    long long s=0;
    cin>>n>>d;
    long long gc;
   for(long long i=1;i<=n;i++){
    cin>>a[i];
   }
   if(n>100){
    e=100;
   }
   else{
    e=n;
   }
   gc=a[2]-a[1];
    long long nl=d/gc;
   if(nl<=1){
      cout<<0<<endl;
   }
   else{
    for(long long i=1;i<=n;i++){
        if(i+2*nl-1<=n)s++;
    }
    cout<<s<<endl;
   }
  }
  return 0;
}

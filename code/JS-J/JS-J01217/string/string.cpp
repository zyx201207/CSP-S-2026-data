#include<bits/stdc++.h>
using namespace std;

int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   string a;
   char add;
   long long  n,x;
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>x>>add;
    for(int j=1;j<=x;j++){
        a+=add;
    }

   }
//gaocheng yige string
long long l=a.length();
long long  sum=0;
  for(int i=0;i<(l>>1);i++){
    if(a[i]!=a[l-1-i]){
        sum++;
    }

  }
  cout<<sum;
   return 0;
}

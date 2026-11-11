#include<bits/stdc++.h>
#define int long long
using namespace std;
char b[200010];
long long a[200010];
signed main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n,g=0;
   string m="";
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    cin>>b[i];
    for(int j=1;j<=a[i];j++){
          m+=b[i];
    }
   }
   for(long long i=0;i<=((long long)m.size()-2)/2;i++){
     long long j=(long long)m.size()-i-1;
     if(m[j]!=m[i])g++;
   }
   cout<<g;
   return 0;
}

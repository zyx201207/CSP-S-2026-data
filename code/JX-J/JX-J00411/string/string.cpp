#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans;
char c[200005];
int main (){
   freopen("string.in","r",stdin);                                            
   freopen("string.out","w",stdout);                                          
   int n;
   string s;
   cin>>n;
   for(int i=1;i<=n;i++){
           cin>>a[i]>>c[i];
          while(a[i]--){
                   s+=c[i];
           }
   }
   for(int i=0;i<=n/2;i++){
        if(s[i]!=s[n-i]){
             ans++;
        }
  }
return 0;
}

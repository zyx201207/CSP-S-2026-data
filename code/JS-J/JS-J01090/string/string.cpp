#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   char s[1000005];
   int n;
   cin>>n;
   int sum=0;
   for(int i=1;i<=n;i++){
      int a;
      char x;
      cin>>a>>x;
      for(int i=1;i<=a;i++){
        sum++;
        s[sum]=x;
      }
   }
   int cnt=0;
   if(sum%2==0){
      int k=0;
      for(int i=1;i<=sum/2;i++){
         if(s[1+k]-'a'!=s[sum-k]-'a'){
            cnt++;
         }
         k++;
      }
   }
    if(sum%2==1){
      int k=0;
      for(int i=1;i<=sum/2+1;i++){
         if(s[1+k]-'a'!=s[sum-k]-'a'){
            cnt++;
         }
         k++;
      }
   }
   cout<<cnt;
   return 0;
}

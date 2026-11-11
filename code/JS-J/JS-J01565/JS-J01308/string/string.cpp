#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n,a,o=0;
   char c;
   string s;
   cin>>n;
   while(n--){
       cin>>a>>c;
       for(int i=1;i<=a;i++){
           s+=c;
       }
   }
   int x=s.size()/2+s.size()%2;
   int x1=x-1;
   int x2=s.size()-x;
   for(int i=0,j=s.size()-1;i<=x1,j>=x2;i++,j--){
       if(s[i]!=s[j]) o++;
   }
   cout<<o;
   fclose(stdin);
   fclose(stdout);
   return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   int n;
   cin>>n;
   string c;
   for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
   }
   string s;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=a[i];j++){
        s+=c[i];
    }
   }
   int sum=0;
   for(int i=0;i<s.length();i++){
    if(s[i]==s[s.length()-i]) sum=sum;
    else sum++;
   }
   cout<<sum-1;
   return 0;
}

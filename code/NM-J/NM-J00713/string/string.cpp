#include <bits/stdc++.h>
using namespace std;
int a;
int main(){
    fropen("string.in","r",stdin);
    fropen("string.out","w",stdout);
int n,ans=0;
string s,b;
cin>>n;
for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
       a=a*b;
       s+=a;
}
 for(int i=s.size();i>=1;i--){
    if(s[i]==s[i-1]){
        ans=s.size()-i;
    }
 }
 cout<<ans;
return 0;
}

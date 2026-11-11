#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
long long n,c=0;cin>>n;
if(n==1){
cout<<"0";return 0;}
else if(n==2){
long long x1,x2;string s1,s2;
cin>>x1>>s1>>x2>>s2;
if(s1==s2)cout<<"0";
else if(x1>=x2)cout<<x2;
else cout<<x1;
}
else{
long long k=n;
while(n--){
string s;long long x;
cin>>x>>s;
string a;
for(int j=0;j<x;j++){
a+=s;
}
string b=a;
reverse(a.begin(),a.end());
for(int i=0;i<a.size();i++){
if(a[i]!=b[i])c++;}
}
cout<<c/2;
}
return 0;}

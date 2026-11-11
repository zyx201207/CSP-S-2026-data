#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,t=0,p=0,q=0;
cin>>n;
int a[n];
char b[n];
for(int i=0;i<n;i++){
cin>>a[i]>>b[i];
if(b[0]==b[i])
p++;
}
if(p==n){
cout<<0;
return 0;
}
if(n==1){
cout<<0;
return 0;
}
if(n==2&&b[0]!=b[1]){
if(a[0]>a[1]){
cout<<a[1];
return 0;
}
else{
cout<<a[0];
return 0;
}
}
if(n==2&&b[0]==b[1]){
cout<<0;
}




return 0;
}

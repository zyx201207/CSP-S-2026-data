#include<bits/stdc++.h>
using namespace std;
long long a[500000];
char b[500000];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
cin>>n;
for(long long i=1;i<=n;i++){
cin>>a[i]>>b[i];
}
if(n==1){
cout<<0;
return 0;
}
long long ans=0,ans1=1e14,ma=0;
char c=b[1];
for(long long i=2;i<=n;i++){
if(b[i]!=c){
ans+=a[i];
}
}
if(n<=30000){
for(long long i=1;i<n;i++){
for(long long j=1;j<=n;j++){
if(b[i]!=b[j]){
ma+=a[j];
}
}
ans1=min(ans1,ma);
ma=0; 
}
}
cout<<min(ans,ans1);
return 0;
}

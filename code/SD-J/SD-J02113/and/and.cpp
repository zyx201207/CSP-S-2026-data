#include<bits/stdc++.h>
using namespace std;
long long a[500000],b[500000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;
for(long long i=1;i<=n;i++){
cin>>a[i];
b[i]=a[i];
}
sort(a+1,a+1+n);
sort(b+1,b+1+n);
if(m==1){
cout<<a[n];
return 0;
}
if(n==m){
for(long long i=2;i<=n;i++){
b[i]=b[i]&b[i-1];
}
cout<<b[n];
return 0;
}
for(long long i=n-m+2;i<=n;i++){
a[i]=a[i]&a[i-1];
}
cout<<a[n];
return 0;
}

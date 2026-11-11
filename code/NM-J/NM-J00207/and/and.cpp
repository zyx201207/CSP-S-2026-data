#include<bits/stdc++.h>
using namespace std;
long long n,m,num,a[1005],b[1005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i];
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) b[i]=b[i]%2;
   if(b[i]==0){
    num=a[i];
   }
}
cout<<num;
return 0;}

#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001],c[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
long long n,m,b=0;cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];b[i]=1;
for(int j=1;j<i;j++){
if(a[j]==a[i])d=j;
}
for(int k=d;k<i;k++){
b[k]=0;
}
for(int l=1;l<=m;l++){
if(d[l]==1)c[l]++;}
}
for(int i=1;i<=m;i++)cout<<c[i]<<" ";
return 0;}

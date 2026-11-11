#include<bits/stdc++.h>
using namespace std;
int a[500005]={};
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m,cnt=0;
cin>>n>>m;
for(int i=0;i<n;i++){
cin>>a[i];
}
if(a[0]!=a[n-1])
for(int i=n-1;i>=0;i--){
cout<<a[i];
}
return 0;
}

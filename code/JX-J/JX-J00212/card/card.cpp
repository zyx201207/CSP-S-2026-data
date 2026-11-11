#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];int u=0;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(m==1){
    cout<<n<<endl;
    return 0;
}
if(m==2){
if(a[n]!=a[n-1]){
  if(a[n-1]<a[n])
 cout<<n-1<<" "<<n;
else{
  cout<<n<<" "<<n-1;
}
}
if(a[n]==a[n-1]){
   for(int i=1;i<=n;i++){
    if(a[i]!=a[n]){ u=a[i];break;}
   }
if(u<a[n-1]){
     cout<<"0"<<" "<<n;
}
else cout<<n<<" "<<"0";
}
}
return 0;
}

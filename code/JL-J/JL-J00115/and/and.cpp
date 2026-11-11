#include<bits/stdc++.h>
using namespace std;
long long a[100000];
long long n,m;
long long max1=0;
int w(int x,int y){
for(int i=1;i<=y;i++){
    x*=x;
}
return x;
}
int f(int x,int y){
int i=0,num=0;
while(x>0&&y>0){
    i++;
    if(x%2==1&&y%2==1){
        num+=w(2,i);
    }
    x/=2;
    y/=2;
}
return num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
   cin>>a[i];
   max1=max(max1,a[i]);
}
if(m==1){
    cout<<max1;
}
if(m==n){
    int sum=a[1];
    for(int i=1;i<=n;i++){
        sum=f(sum,a[i]);
    }
cout<<sum;
}
if(m==2){
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;i++){
            int p=f(a[i],a[j]);
            ans=max(ans,p);
        }
    }
cout<<ans;
}
return 0;
}

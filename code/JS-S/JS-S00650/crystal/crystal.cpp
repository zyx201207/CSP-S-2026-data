#include<bits/stdc++.h>
using namespace std;
int n,m,c,ma=-100005;
int a[500005],b[500005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;

for(int i=1;i<=n;i++){
  cin>>c;
  if(c>0)
  a[c]++;
  else b[0-c]++;
  ma=max(c,ma);
}
a[ma+1]=1;

int l=500000,num=0,i=0,r=499999;
int x;
while(r){
while(b[r]==0&&r!=0){
        r--;}
if(r==0)break;
if(num+i*(l-r)*b[r]>m){
    cout<<i+(m-num)/(l-r);
    return 0;
}
num+=i*(l-r)*b[r];
l=r;
i+=b[r];
r--;
}
l=0-l;
while(r<=ma){
while(a[r]==0&&r<=ma)r++;
if(num+i*(r-l)*a[r]>m){
    cout<<i+(m-num)/(r-l);
    return 0;
}
num+=i*(r-l)*a[r];
l=r;
i+=a[r];
r++;
}
cout<<n;
return 0;
}

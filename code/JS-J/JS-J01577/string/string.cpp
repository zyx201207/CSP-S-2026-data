#include<bits/stdc++.h>
using namespace std;
int a[200002]={};
char c[200002]={};
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
long long ans=0,sum=0,ll=0;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i]>>c[i];
ans+=a[i];
}
if(ans%2==0){
ans/=2;
}
else{
ans-=1;
ans/=2;
}
int l=1,r=n;
for(int i=0; ;i++){
if(a[l]>=a[r]&&c[l]!=c[r]){
if(ll+a[r]>=ans){
sum+=ans-ll;
break;
}
ll+=a[r];
sum+=a[r];
r-=1;
a[l]-=a[r+1];
}
else if(a[l]>=a[r]&&c[l]==c[r]){
if(ll+a[r]>=ans){
break;
}
ll+=a[r];
r-=1;
a[l]-=a[r+1];
}
else if(a[l]<a[r]&&c[l]!=c[r]){
if(ll+a[l]>=ans){
sum+=ans-ll;
break;
}
ll+=a[l];
sum+=a[l];
l+=1;
a[r]-=a[l-1];
}
else if(a[l]<a[r]&&c[l]==c[r]){
if(ll+a[l]>=ans){
break;
}
ll+=a[l];
l+=1;
a[r]-=a[l-1];
}
}
cout<<sum;
return 0;
}

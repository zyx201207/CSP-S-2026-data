#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
if(n==1&&m!=0){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<1;
}
if(n==2&&m!=0){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if (a[2]-a[1]>m)cout<<1;
    else cout<<2;
    }
if(n==3&&m!=0){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long num=0;
    num+=(a[3]-a[2])+(a[3]-a[1]);
    if(num<=m)cout<<3;
    else if (a[3]-a[2]<=m||a[2]-a[1]<=m)cout<<2;
    else cout<<0;
}
if(n==4&&m!=0){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long sum=a[4]-a[3]+a[4]-a[2]+a[4]-a[1];
    if(sum<=m)cout<<4;
    else if (a[4]-a[3]+(a[4]-a[2])<=m||a[3]-a[2]+(a[3]-a[1])<=m)cout<<3;
    else if  (a[2]-a[1]<=m||a[3]-a[2]<=m||a[4]-a[3]<=m)cout<<2;
    else cout<<1;
}
if(n==5&&m!=0){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long cnt=a[5]-a[4]+a[5]-a[3]+a[5]-a[2]+a[5]-a[1];
    if(cnt<=m)cout<<5;
    else if(a[5]-a[4]+a[5]-a[3]+a[5]-a[2]<=m||a[4]-a[3]+a[4]-a[2]+a[4]-a[1]<=m)cout<<4;
    else if(a[5]-a[4]+a[5]-a[3]<=m||a[4]-a[3]+a[4]-a[2]<=m||a[3]-a[2]+a[3]-a[1]<=m)cout<<3;
    else if(a[2]-a[1]<=m||a[3]-a[2]<=m||a[4]-a[3]<=m||a[5]-a[4]<=m)cout<<2;
    else cout<<1;
}
if(m==0)cout<<0;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int num[100000];//qunbao shuliang,dp[30][30],qun[30][30]
int main(){
   freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
  int m,n;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>num[i];
}
//==shuru
int sum=0;
//teshu m=1
if(m==1){
        int maxn=0;
    for(int i=1;i<=n;i++){
        maxn=max(num[i],maxn);
    }
    cout<<maxn;
    return 0;
}
if(m==n){
    sum=num[1];
    for(int i=2;i<=n;i++){
        sum=num[i]&sum;
    }
    cout<<sum;
    return 0;
}
int maxw=0,ans=n;
if(m==3){
    for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++){
        int zhong=num[i]&num[j];
    for(int q=j+1;q<=n;q++){
        maxw=max(zhong&num[q],maxw);
    }

}
}
}
if(m==2){
    for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++){
        maxw=max(maxw,num[i] & num[j]);



}}}
if(m==4){

    for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++){
        int zhong1=num[i]&num[j];
    for(int q=j+1;q<=n;q++){
        int zhong2=num[q]&zhong1;
       for(int z=q+1;z<=n;z++){
        maxw=max(maxw,zhong2&num[z]);
       }
    }

}
}
}
  if(m==5){
 if(m==6){

    for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++){
        int zhong1=num[i]&num[j];
    for(int q=j+1;q<=n;q++){
        int zhong2=num[q]&zhong1;
       for(int z=q+1;z<=n;z++){
      int  zhong3=num[z]&zhong2;
           for(int c=z+1;c<=n;c++){
               int  zhong4=num[c]&zhong2;
                 for(int d=c+1;d<=n;d++){
        maxw=max(maxw,zhong4&num[d]);
       }
       }}}}}

    for(int i=1;i<=n;i++){
for(int j=i+1;j<=n;j++){
        int zhong1=num[i]&num[j];
    for(int q=j+1;q<=n;q++){
        int zhong2=num[q]&zhong1;
       for(int z=q+1;z<=n;z++){
      int  zhong3=num[z]&zhong2;
           for(int c=z+1;c<=n;c++){
        maxw=max(maxw,zhong3&num[c]);
       }
       }}}}}}
cout<<maxw;
   return 0;
}

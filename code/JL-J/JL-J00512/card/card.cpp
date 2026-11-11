#include<bits/stdc++.h>
using namespace std;
int n,m,p[300005],t[300005],ma=0,qq,sum[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>p[i];
}
for(int j=0;j<n;j++){
   for(int i=j;i<n;i++){
    t[p[i]]++;
    ma=max(ma,p[i]);
    if(t[p[i]]==2){
        sort(t,t+ma);
        while(t[qq]!=0){
        t[qq]=0;
        qq++;}
        t[p[i]]++;
    } }
    for(int i=0;i<=ma;i++){
            if(t[i]!=0)
            sum[i]++;
    }
    sort(t,t+ma);
        while(t[qq]!=0){
        t[qq]=0;
        qq++;}
    ma=0;
}
for(int i=0;i<m;i++){
    cout<<sum[i]<<' ';
}
return 0;
}

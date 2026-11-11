#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=0;
ll a[500010];
struct node{
    ll su=0;
    ll zhi=0;
}num[500010];
int t=0;
ll check(int w,ll c){
    ll s=num[w-1].su+num[w].su;
    c-=num[w-1].su*(num[w].zhi-num[w-1].zhi);
    for(int i=w-2;i>0;i--){
        if(c<=num[i].su*(num[w].zhi-num[i].zhi)){
            s+=c/(num[w].zhi-num[i].zhi);
            return s;
        }
        else{
            s+=num[i].su;
            c-=num[i].su*(num[w].zhi-num[i].zhi);
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i==1){
            num[++t].su++;
            num[t].zhi=a[i];
        }
        else if(a[i]==a[i-1]){
            num[t].su++;
        }
        else{
            num[++t].su++;
            num[t].zhi=a[i];

        }
        ans=max(ans,num[t].su);
    }
    if(m==0){
        printf("%d",ans);
        return 0;
    }
    for(int i=2;i<=t;i++){
        if(num[i-1].su*(num[i].zhi-num[i-1].zhi)==m){
            ans=max(ans,num[i-1].su+num[i].su);
        }
        else if(num[i-1].su*(num[i].zhi-num[i-1].zhi)>m){
            ans=max(ans,m/(num[i].zhi-num[i-1].zhi)+num[i].su);
        }
        else{
            ans=max(ans,check(i,m));
        }
    }
    printf("%d",ans);
    return 0;
}

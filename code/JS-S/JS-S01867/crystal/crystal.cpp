#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=-1;
ll m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll sum=0;
    int l=1;
    for(int r=1;r<=n;r++){
        sum+=a[r];
        while(a[r]*(r-l+1)-sum>m&&l<r){
            sum-=a[l];
            l++;
        } 
       ans=max(ans,r-l+1);
    }
    printf("%d",ans);
    return 0;
}
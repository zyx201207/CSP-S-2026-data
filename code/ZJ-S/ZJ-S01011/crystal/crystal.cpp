#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define LL long long
int n;
LL m;
LL a[N];
bool check(int x){
    LL res=0;
    for(int i=1;i<x;i++)res+=a[x]-a[i];
    if(res<=m)return 1;
    for(int i=1;i<=n-x;i++){
        res-=a[x+i-1]-a[i];
        res+=(LL)(x-1)*(a[x+i]-a[x+i-1]);
        if(res<=m)return 1;
    }return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }cout<<l;
    return 0;
}

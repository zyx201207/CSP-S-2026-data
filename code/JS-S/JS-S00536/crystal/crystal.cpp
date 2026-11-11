
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n,mx;
ll a[500010],sum,s[500010],m;
ll clac(int l,int r){
    return (r-l)*a[r]-(s[r-1]-s[l-1]);
}
int fd(int x){
    int l=1,r=x;
    while(l<=r){
        int mid=(l+r)>>1;
        if(clac(mid,x)<=m)r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int nct=i-fd(i)+1;
        mx=max(nct,mx);
    }
    cout<<mx;
    return 0;
}
//Oct31==Dec25?

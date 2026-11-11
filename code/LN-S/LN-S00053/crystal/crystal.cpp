#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int ef(int l,int r,int x){
    int mid=0;
    while(l<r){
        mid=(l+r)/2;long long h=b[x]-b[mid-1],p=(long long)(x-mid+1)*a[x],c=p-h;
        if(c>m)l=mid+1;
        else r=mid;
    }
    return x-l+1;
}
/*
5 5
1 2 4 8 9
*/
int main(){
    //T1 time used:1h
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long ls=(long long)ef(1,i,i);
        ans=max(ls,ans);
    //cout<<ls<<" "<<i-(ls-1)<<endl;
    }
    cout<<ans;
    return 0;
}

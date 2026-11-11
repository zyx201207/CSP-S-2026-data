#include<bits/stdc++.h>
using namespace std;
int n,ans;
unsigned long long a[500005],b[500005],c[500005],d[500005],m;
unsigned long long op(int l,int r){
    return (r-l)*a[r]-b[r-1]+b[l-1];
}
int find(int i){
    int l=i,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(op(i,mid)<=m)l=mid+1;
        else r=mid-1;
    }
    if(op(i,mid)<=m)return mid-i+1;
    else return r-mid+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i]-a[i-1];
        b[i]=b[i-1]+a[i];
    }
    std::stable_sort(a+1,a+n+1);
    std::stable_sort(c+1,c+n+1);
    if(c[n]==c[1]){
        long long x=(long long)sqrt(2*m)+1;
        while((x*x+x)*c[1]>2*m)x--;
        cout<<x;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,find(i));
    }
    cout<<ans;
    return 0;
}

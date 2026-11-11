#include<bits/stdc++.h>
#define int long long 
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int n,m,a[500010],sum[500010];
bool check(int mid){
    for(int i=1;i+mid-1<=n;i++){
        int l=i,r=i+mid-1;
        int x=a[r]*mid-(sum[r]-sum[l-1]);
        if(x<=m)return 1;
    }
    return 0;
}
signed main(){
    file("crystal");
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,l,r;
long long m,a[N],sum[N],res;
bool check(int k){
    res=0;
    for(int i=1;i<=k;i++) res+=a[k]-a[i];
    for(int i=k;i<=n;i++){
        if(res<=m) return true;
        res+=(a[i+1]-a[i])*(k-1)-a[i]+a[i-k+1];
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    l=1,r=n+1;
    while(l<r-1){
        int mid=l+r>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<l<<"\n";
    return 0;
}
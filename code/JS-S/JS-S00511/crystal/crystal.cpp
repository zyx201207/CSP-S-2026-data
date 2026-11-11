#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
//long long sum[500005];
bool check(long long x){
    int p=lower_bound(a+1,a+n+1,x)-a;
    // p--;
    // long long tmp=x*p-sum[p];
    long long tmp=0;
    for(int i=1;i<p;i++) tmp+=x-a[i];
    return tmp<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    long long l=a[1],r=a[n];
    while(l<r){
        long long mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<upper_bound(a+1,a+n+1,r)-a-1;
    return 0;
}
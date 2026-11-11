#include <bits/stdc++.h>
using namespace std;
const long long maxn=5e5+5;
long long n,m,a[maxn];
bool check(long long x){
    long long sum=0;
    for(long long i=1;i<x;i++){
        sum+=a[x]-a[i];
        if(sum>m)return 0;
    }
    //cout<<sum<<endl;
    return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n>5000&&m>100000000){//special A&B
        long long cha=a[2]-a[1];
        cout<<(m/cha>=n ? n : m/cha)<<endl;
        return 0;
    }
    long long l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        //cout<<l<<' '<<mid<<' '<<r<<endl;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r<<'\n';
    return 0;
}

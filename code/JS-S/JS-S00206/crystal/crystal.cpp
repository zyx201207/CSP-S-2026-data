#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll n,m,a[N],b[N],total[N];
bool check(ll len){
    ll minx=0;
    for(int i=1;i<=len-1;i++) minx+=i*b[i];
    ll sum=minx;
    for(int i=2;i<=n-len+1;i++){
        sum=sum-total[len+i-2]+total[i-2]+len*b[len+i-1];
        minx=min(minx,sum);
    }
    if(minx<=m) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
        b[i]=a[i+1]-a[i];
        total[i]=total[i-1]+b[i];
    }
    ll l=1,r=n;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<"\n";
    return 0;
}

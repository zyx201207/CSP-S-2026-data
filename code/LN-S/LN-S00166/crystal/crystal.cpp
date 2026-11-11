#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],l,r,sum;
bool check(int x){
    if(x==1)return 1;
    sum=0;
    for(int i=1;i<=x;i++)sum+=a[i];
    if(x*a[x]-sum<=m)return 1;
    for(int i=x+1;i<=n;i++){
        sum-=a[i-x],sum+=a[i];
        if(x*a[i]-sum<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+n+1),l=1,r=n;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout << l;
    return 0;
}
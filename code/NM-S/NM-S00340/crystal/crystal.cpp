#include<bits/stdc++.h>
using namespace std;
long long l,r,mid,n,m,a[500005],s[500005];
bool check(long long x){
    for(int i=1;i<=n-x+1;i++){
        if(a[i+x-1]*x-(s[i+x-1]-s[i-1])<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    l=1,r=n;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}

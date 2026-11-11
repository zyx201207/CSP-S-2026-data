#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],c[N],s[N],n,m,ans;
bool check(int mid){
    for(int i=1;i<=n;i++){
        if(i<mid)continue;
        else{
            if(a[i]*(mid-1)-(s[i-1]-s[i-mid])<=m){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    ll L=1,R=1e6;
    while(L<=R){
        long long mid=(L+R)/2;
        if(check(mid)){
            ans=mid;
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    cout<<ans;
    return 0;
}

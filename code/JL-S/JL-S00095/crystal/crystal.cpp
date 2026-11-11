#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],pre[N];
ll m;
int n;
bool check(int mid){
    for(int i=n;i>=mid-1;i--){
        ll sum=a[i]*mid-pre[i]+pre[i-mid];
        if(sum<=m){return 1;}
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];

    }
    int l=1,r=n,mid=0;

    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}

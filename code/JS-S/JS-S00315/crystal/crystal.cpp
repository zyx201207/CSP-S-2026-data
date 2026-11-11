#include<bits/stdc++.h>
using namespace std;
long long  a[500001],s[500001];long long m;int n;
bool check(int k){
    for(int i=k;i<=n;i++){
        if(a[i]*k-(s[i]-s[i-k])<=m)return 1;
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
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}

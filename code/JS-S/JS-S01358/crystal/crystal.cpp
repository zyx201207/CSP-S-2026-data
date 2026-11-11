#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001],s[500001];
bool check(int x){
    long long ans=LONG_LONG_MAX;
    for(int i=1;i<=n-x+1;i++){
        ans=min(ans,a[i+x-1]*x-(s[i+x-1]-s[i-1]));
        //cout<<a[i+x-1]*x<<' '<<(s[i+x-1]-s[i-1])<<' '<<a[i+x-1]*x-(s[i+x-1]-s[i-1])<<' '<<a[i+x-1]<<' '<<i+x-1<<"\n";
    }
    return ans<=m;
}
int erfen(){
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(mid==l){
            mid=r;
        }
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
        //cout<<mid<<' '<<l<<' '<<r<<"\n";
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    cout<<erfen();
    return 0;
}

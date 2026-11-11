#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int n;
bool cmp(long long x,long long y){
    return x<y;
}
bool check(int x,long long m){
    long long add=0;
    for(int i=2;i<=x;i++){
        add+=(a[i]-a[i-1])*(i-1);
    }
    long long minadd=add;
    if(add<=m){
        return 1;
    }
    for(int i=1;i+x<=n;i++){
        add=add+(a[i+x]-a[i+x-1])*(x-1)-a[i+x-1]+a[i];
        minadd=min(add,minadd);
    }
    if(minadd<=m){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid,m)==1){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,ans;
long long m,a[500005],b[500005];
bool check(int x){
    for(int i=x;i<=n;i++){
        if((x-1)*a[i]-(b[i-1]-b[i-x])<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)==1)ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}

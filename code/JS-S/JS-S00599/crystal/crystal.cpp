#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int a[500010],h[500010];

int sum(int l,int r){
    return h[r]-h[l-1];
}
bool check(int mid,int x){
    if(a[x]*(x-mid)-sum(mid,x-1)<=m)return 1;
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        h[i]=h[i-1]+a[i];
    }
    int ans=1;
    for(int i=2;i<=n;++i){
        int l=1,r=i-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
ll a[500005];
ll sum[500005],sum2[500005];
int erfen(int l,int r){
    if(l == r){
        bool p = false;
        for(int i = l;i <= n;++i){
            int e = i-l+1;
            if(sum2[i]-sum2[e]-(a[i]-a[e])*(e-1) <= m){
                p = true;
                break;
            }
        }
        if(p){
            return l;
        }
        else{
            return l-1;
        }
    }
    int mid = (l+r)/2;
    bool b = false;
    for(int i = mid;i <= n;++i){
        int e = i-mid+1;
        if(sum2[i]-sum2[e]-(a[i]-a[e])*(e-1) <= m){
            b = true;
            break;
        }
    }
    if(b){
        erfen(mid+1,r);
    }
    else{//b = false
        erfen(l,mid);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;++i) sum[i] = (a[i]-a[i-1]) * (i-1);
    for(int i = 1;i <= n;++i) sum2[i] = sum[i]+sum2[i-1];
    int ans = erfen(1,n);
    cout<<ans;
    return 0;
}

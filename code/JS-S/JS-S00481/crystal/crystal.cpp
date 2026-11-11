#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[500005];

int diff[500005],diffArr[500005];
int solve(int p){
    int l=0,r=p,mid;
    while(l+1<r){
        mid = (l+r) >> 1;
        if(diffArr[mid]-diffArr[p]-diff[p]*(p-mid)<=m){
            r  = mid;
        }else{
            l = mid;
        }
    }
    return r;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        diff[i] = a[i+1] - a[i];
    }
    for(int i=n-1;i>=1;i--){
        diff[i] += diff[i+1];
        diffArr[i] = diff[i] + diffArr[i+1];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<diff[i]<<' '<<diffArr[i]<<'\n';
    // }
    int ans = 1;
    for(int i=1;i<=n;i++){
        // cout<<solve(i)<<' ';
        ans = max(ans,i-solve(i)+1);
    }
    cout<<'\n'<<ans;
    return 0;
}
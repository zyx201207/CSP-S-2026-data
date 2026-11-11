#include<bits/stdc++.h>
using namespace std;
#define int long long


int n,m;
int a[500005]={};
int sum[500005]={};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }

    int r=1;
    int ans=0;

    for(int l=1;l<=n;l++){
        while(a[r]*(r-l+1)-sum[r]+sum[l-1]<=m&&r<=n){
            r++;
        }
        r--;
        ans=max(ans,r-l+1);
    }

    cout<<ans<<endl;


    return 0;
}
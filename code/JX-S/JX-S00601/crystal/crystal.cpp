#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int sum[N];
bool check(int x){
    int minn=LLONG_MAX;
    for(int r=x;r<=n;r++){
        int l=r-x+1;
        int temp=(r-l)*a[r]-(sum[r-1]-sum[l-1]);
        minn=min(temp,minn);
    }
    if(minn<=m){
        return true;
    }
    else {
        return false;
    }
}
int ans=0;
signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else {
            r=mid-1;
        }
   }
    cout<<ans;
    return 0;
}

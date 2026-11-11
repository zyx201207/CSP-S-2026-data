#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
inline bool cmp(int& x,int& y){
    return x<y;
}
inline bool check(int x){
    int sum=0;
    for(int i=1;i<=x;i++){
        sum+=a[x]-a[i];
    }
    if(sum<=m){
        return 1;
    }
    for(int i=x+1;i<=n;i++){
        sum+=(a[i]-a[i-1])*x;
        sum-=(a[i]-a[i-x]);
        if(sum<=m){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int l=1,r=n,mid,ans=1;
    while(l<=r){
        mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}

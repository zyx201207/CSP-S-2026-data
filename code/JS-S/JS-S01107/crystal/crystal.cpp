#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q[500005];
inline bool check(int x){
    for(int i=x;i<=n;i++){
        long long costnum=a[i]*x-(q[i]-q[i-x]);
        if(costnum<=m)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //q[i]=q[i-1]+q[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    int l=1,r=n,ans=-1;
    while(l<=r){
        int mid=((l+r)>>1);
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}

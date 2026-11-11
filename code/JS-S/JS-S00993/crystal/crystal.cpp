#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,m;
int a[MAXN];
int sum[MAXN];
//int zuixiaocishu=1e18;
bool check(int x){
    int zuixiaocishu=1e18;
    for(int i=1;i+x-1<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(j-i+1==x){
                int cishu=1LL*a[j]*(x-1)-(sum[j-1]-sum[i-1]);
                if(cishu<0) continue;
                zuixiaocishu=min(zuixiaocishu,cishu);
            }
        }
    }
    if(zuixiaocishu<=m) return true;
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    //sum[0]=1;
    int l=1,r=n;
    int ans=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    //bool ok=check(4);
    //cout<<zuixiaocishu<<endl;
    cout<<ans;
}

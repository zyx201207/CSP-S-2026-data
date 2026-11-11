#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
int n;
ll m;
ll a[N];
ll s[N];
int l,r,mid,res;
ll query(int L,int R){
    return s[R]-s[L-1];
}
bool check(int L,int R){
    return ((1ll*a[R]*(R-L+1ll)-1ll*query(L,R))<=(m));
}
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("crystal1/crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n;
    cin>>m;
    s[0]=0ll;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ans=1;
    for(int i=1;i<=n;i++){
        l=1;
        r=i;
        res=i;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid,i)){
                r=mid-1;
                res=mid;
            }else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<'\n';
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int r=1,l=1,su=0,ans=0;
    for(;r<=n;r++){
        su+=a[r];
        int mid=a[r];
        int id=r;
        int res=((mid*(id-l+1))-(sum[id]-sum[l-1]));
        while(res>m&&l<r){
            su-=a[l];
            l++;
            mid=su/(r-l+1);
            id=lower_bound(a+1,a+1+n,mid)-a-1;
            // cerr<<id<<'\n';
            res=((mid*(id-l+1))-(sum[id]-sum[l-1]))+(sum[r]-sum[id])-(mid*(r-id));
        }
        ans=max(ans,r-l+1);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=abs(a[i]+1027);
    }
    cerr<<cnt<<'\n';
    cout << ans;
    return 0;
}
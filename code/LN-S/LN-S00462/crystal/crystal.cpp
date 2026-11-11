#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
int n,ans;
ll m,a[N],sum[N];
int check(int x){
    int l=1,r=x,ret=x;
    while(l<=r){
        int mid=l+r>>1;
        long long w=a[x]*(x-mid+1)-sum[x]+sum[mid-1];
//        cout<<l<<' '<<r<<' '<<mid<<' '<<w<<endl;
        if(w<=m){
            ret=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return x-ret+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)ans=max(ans,check(i));
    cout<<ans;
    return 0;
}

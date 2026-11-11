#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],cnt[N];
long long getnumber(long long x,long long y){
    return cnt[y]-cnt[x]-(a[y]-a[x])*(x-1);
}
long long solve(long long n,long long m){
    long long l=1,r=n,ans=0;
    while(l<r){
        long long mid=(l+r)>>1;
        if(getnumber(mid,n)>m){
            l=mid+1;
            ans=l;
        }else{
            r=mid;
        }
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    cnt[1]=0;
    for(int i=2;i<=n;i++){
        cnt[i]=cnt[i-1]+(a[i]-a[i-1])*(i-1);
    }
    for(long long i=1;i<=n;i++){
        if(cnt[i]<=m){
            ans=max(ans,i);
        }else{
            int p=solve(i,m);
            ans=max(ans,i-p+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}

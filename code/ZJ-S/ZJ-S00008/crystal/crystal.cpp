#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n,m,a[maxn],pre[maxn],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long l=1,r=i,k=i;
        while(l<=r){
            long long mid=l+r>>1;
            long long x=a[i]*(i-mid+1);
            long long y=x-(pre[i]-pre[mid-1]);
            // cerr<<i<<" "<<mid<<" "<<y<<"\n";
            if(y<=m){
                r=mid-1;
                k=min(k,mid);
            }
            else l=mid+1;
        }
        ans=max(ans,i-k+1);
    }
    cout<<ans<<"\n";
    return 0;
}
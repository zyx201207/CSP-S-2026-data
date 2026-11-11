#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],f[N],ans,b[N],cnt,s[N],s1[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    for(int i=1;i<=n;i++){
        ll l=0,r=i+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(f[i]-(a[i]-a[i-mid])*(i-mid)-f[i-mid]<=m){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans=max(ans,r);
    }
    cout<<ans;
    return 0;
}
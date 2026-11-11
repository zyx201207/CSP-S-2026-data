#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+16;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,ans=0;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1,l,r,mid;i<=n;++i){
        s[i]=s[i-1]+a[i];
        l=1,r=i;
        while(l<=r){
            mid=l+r>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
                ans=max(ans,i-mid+1);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
//315275
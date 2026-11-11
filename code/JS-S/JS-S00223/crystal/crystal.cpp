#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N = 5e5+5;
ll a[N],b[N],m;
int n,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m){
                r=mid-1;
                ans=max(ans,i-mid+1);
            }
            else l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
constexpr int N=5e5+10;
ll a[N],m,sum[N];
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r+1)/2;
            if((mid-i+1)*a[mid]-sum[mid]+sum[i-1]<=m)
                l=mid;
            else
                r=mid-1;
        }
        ans=max(ans,l-i+1);
    }
    cout<<ans;

    return 0;
}

#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int kmaxn=5e5+10;
int n,m,a[kmaxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int r=1,sum=0,l=1;r<=n;r++){
        sum+=a[r];
        while((r-l+1)*a[r]-sum>m){
            sum-=a[l];l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}
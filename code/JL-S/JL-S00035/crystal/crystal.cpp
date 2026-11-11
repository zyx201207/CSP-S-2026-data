#include<bits/stdc++.h>
using namespace std;
long long ll;
const int maxn=5e5+10;
ll a[maxn],sum[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1;
    int ans=0;
    for(int r=1;r<=n;r++){
        while (a[r]*(r-l+1)-(sum[r]-sum[r-1])>m){
            l++;
        }
        ans=max(ans,r-1+1);
    }
    cout<<ans<<endl;
    return 0;
}

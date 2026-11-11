#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
ll n,m,a[500005],d[500005],ans;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    ll l=1,r=1,cnt=0;
    while(cnt+(r+1)*d[r+1]<=m) {
        cnt+=((r+1)*d[r+1]);
        r++;
    }
    while(l<=r&&r<=n){
        ans=max(ans,r-l+1);
        r++;
        cnt+=((r-l+1)*d[r]);
        while(cnt>m&&l<=r){
            cnt-=(a[r]-a[l]);
            l++;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}

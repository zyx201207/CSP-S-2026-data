#include<bits/stdc++.h>
using lli=long long;
using namespace std;
const int N=500005;
int n;
lli m,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    /*for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }*/
    int l=1;
    int ans=1;
    for(int i=2;i<=n;i++){
        lli d=(a[i]-a[i-1])*(i-l);
        while(d>m){
            d-=(a[i]-a[i-1]);
            m+=a[i-1]-a[l++];
        }
        m-=d;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}

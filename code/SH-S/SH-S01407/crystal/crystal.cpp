#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
using ll=long long;
const int N=1000009;
int n,m;
ll a[N],s[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int res=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(1ll*a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid-1,ans=mid;
            else l=mid+1;
        }
        res=max(res,i-ans+1);
    }
    cout<<res<<"\n";
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--) 
    solve();
    return 0; 
}
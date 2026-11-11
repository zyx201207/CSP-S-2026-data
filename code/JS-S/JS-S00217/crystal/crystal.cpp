#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll n,m,ans;
ll a[maxn],s[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
            s[i]=s[i-1]+a[i];
            //cout<<s[i]<<" ";
    }
   // cout<<endl;
    ll l=1;
    ll r=1;
    for(;r<=n;r++){
        while((r-l+1)*a[r]-(s[r]-s[l-1])>m){
            l++;
            if(l==r)break;
        }
        ans=max(ans,r-l+1);
        //cout<<l<<" "<<r<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

/*

5 8
-3 -1 2 2 7

*/

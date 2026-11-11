#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n,a[N],s[N],l,r,m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        s[i] = a[i] + s[i-1];
    }
    for(ll l = 1,r = 1;r<=n;r++){
        while((r-l+1)*a[r] - (s[r] - s[l-1]) > m)l++;
        ans = max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}

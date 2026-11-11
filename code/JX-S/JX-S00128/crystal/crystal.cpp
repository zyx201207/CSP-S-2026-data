#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+2;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);int p=1,ans=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        while(p<i&&(i-p+1)*a[i]>s[i]-s[p-1]+m) p++;
        ans=max(ans,i-p+1);
    }
    cout<<ans<<'\n';
    return 0;
}
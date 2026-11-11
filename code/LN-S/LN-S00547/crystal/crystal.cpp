#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,ans=0;
    for(int i=1;i<=n;i++){
        while(l<=i&&a[i]*(i-l+1)-(s[i]-s[l-1])>m) l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;

    return 0;
}

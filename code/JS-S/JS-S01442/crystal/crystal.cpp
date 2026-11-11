#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++) a[i]=a[i+1]-a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        int tans=0; long long cnt=0;
        while(cnt<=m && tans<n-1) cnt+=a[++tans]*tans;
        ans=max(ans,tans);
        if(n-i<ans) break;  // impossible for bigger answer
    }
    cout<<ans;
    return 0;
}

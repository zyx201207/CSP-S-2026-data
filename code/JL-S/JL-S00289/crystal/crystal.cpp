#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long> pre(n+1,0);
    for (int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
    int ans=1; 
    int l=0;
    for (int r=0;r<n;r++) {
        while (l<=r) {
            long long cost=a[r]*(r-l+1LL)-(pre[r+1]-pre[l]);
            if (cost<=m) break;
            l++;
        }
        ans=max(ans,r-l+ 1);
    }
    cout<<ans<<"\n";
    return 0;
}

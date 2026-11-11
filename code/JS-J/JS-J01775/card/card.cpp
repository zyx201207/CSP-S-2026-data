#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n, m, a[N], b[N], ans[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        vector<int> ton(m+1, 0);
        int l=N, r=0;
        for(int j=i;j<=n;j++){
            if(ton[a[j]]!=0&&!(ton[a[j]]>=l&&ton[a[j]]<=r)) l=min(l, ton[a[j]]), r=max(r, j-1), ton[a[j]]=j;
            else ton[a[j]]=j;
        }
        for(int j=1;j<=m;j++) if(!(ton[j]>=l&&ton[j]<=r)) ans[j]++;
    }
    for(int i=1;i<=m;i++) cout << ans[i] << ' ';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[500005], mark[500005];
ll ans[300005];
struct node {
    int st, en, state;
}b[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) {
        memset(mark, 0, sizeof mark);
        memset(b, 0, sizeof b);
        for (int j=i; j<=n; j++) {
            if (b[a[j]].st==0) {
                b[a[j]].st=j;
            }else if (mark[b[a[j]].st]==0) {
                for (int k=b[a[j]].st; k<j; k++) {
                    mark[k]=1;
                }
                b[a[j]].st=j;
            }else {
                b[a[j]].st=j;
            }
        }
        for (int j=i; j<=n; j++) {
            if (mark[j]==0) ans[a[j]]++;
        }
    }
    for (int i=1; i<=m; i++) cout<<ans[i]<<" ";
    return 0;
}

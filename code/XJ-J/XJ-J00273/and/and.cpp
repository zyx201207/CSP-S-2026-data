#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
bool vis[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int j=30;j>=0;j--){
        int tmp=0;
        for (int i=1;i<=n;i++)
            if ((a[i]>>j)&1 && !vis[i]) tmp++;
        if (tmp < m) continue;
        ans |= (1<<j);
        for (int i=1;i<=n;i++)
            if (!((a[i] >> j)&1)) vis[i]=1;
    }
    cout << ans << '\n';
    return 0;
}
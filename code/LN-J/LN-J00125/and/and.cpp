#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    if(m==1){
        int maxn=-10;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            maxn=max(maxn,a[i]);
        }
        cout << maxn;
        return 0;
    }
    else if(m==n-1){
        int ans=0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            ans=ans&a[i];
        }
        cout << ans;
        return 0;
    }
    for(int i=1;i<=n;i++) cin >> a[i];
    int maxn=-10;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            maxn=max(maxn,(a[i]&a[j]));
        }
    }
    cout << maxn;
    return 0;
}
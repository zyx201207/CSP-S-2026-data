#include <bits/stdc++.h>

#define ll long long
using namespace std;
int a[200010];
int n, m;

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= m; i++)
    {
        int ans=0;
        for(int j=i;j<=n;j++)
        {
            if(a[i]==j){
                ans++;
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}

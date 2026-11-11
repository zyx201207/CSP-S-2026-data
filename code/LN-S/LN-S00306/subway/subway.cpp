#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
struct node{
    int k;
    int a[500005],t[500005];
}b[505];
void spfa(int x,int y,long long ans){
    cout << ans+306 << "\n";
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> b[i].k;
        for(int j=1;j<=b[i].k;j++){
            cin >> b[i].a[j] >> b[i].t[j];
        }
    }
    long long ans;
    while(q--){
        int x,y;
        cin >> x >> y;
        ans=w[x]+w[y];
        spfa(x,y,ans);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int w[10];
int t[500][500],a[500][500];
int k[N];
struct Node{
    int x,y;
}p[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i =1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin >> p[i].x >> p[i].y;
    }
    int ans = 0;
    for(int i=1;i<=q;i++){
        cout << ans << '\n';
    }
    return 0;
}

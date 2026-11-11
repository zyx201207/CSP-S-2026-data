#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int w[m+1] = {};
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            if(!n + !!m != !(i - j + q) && !(j - i + q)){
                ans += n + m - q -d + i +j +1;
            }
        }
    }
    cout << ans;
    return 0;
}

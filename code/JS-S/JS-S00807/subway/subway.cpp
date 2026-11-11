#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> c;
        for(int i=0;i<c;i++){
            cin >> d >> d;
        }
    }
    while(q--){
        cin >> c >> d;
        cout << a[c]+a[d] << '\n';
    }
}

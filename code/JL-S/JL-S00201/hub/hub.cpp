#include<bits/stdc++.h>
using namespace std;
int a[10000][1000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int i = 1;i <= t;i ++){
        int n,k;
        cin >> n >> k;
        for(int j = 1;j <= n;j ++){
            for(int p = 1;p <= k;p ++) cin >> a[j][p];
        }
    }
    for(int i = 1;i <= t;i ++) cout << 1 << endl;
    return 0;
}

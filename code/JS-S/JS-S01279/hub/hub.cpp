
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1;


int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin >> c >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int tmp;
        for(int i=1;i<n;i++)cin >> tmp >> tmp;
        cout << n-1 << '\n';
    }

    return 0;
}

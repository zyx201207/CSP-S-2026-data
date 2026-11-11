#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+1;
long long a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int c,t;cin >> c >> t;
    while(t--){
        int n,d;cin >> n >> d;
        for(int i = 1;i<=n;i++) cin >> a[i];
        if(d<a[2]-a[1]) cout << 0;
        else cout << n-2;
    }
}


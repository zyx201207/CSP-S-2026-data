#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,m,a[N];
int ans[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cout<<n+1-i<<" ";
    }

    return 0;
}

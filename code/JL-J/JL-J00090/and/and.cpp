#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
string s[N];
int maxn=-INF;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    cout<<maxn<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
map<int,int> cnt;
int a[maxn],mx[maxn];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}

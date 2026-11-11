#include <bits/stdc++.h>
using namespace std;
int a[20010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int maxn=-1;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxn=max(a[i],maxn);
    }


    cout << maxn;
    return 0;
}

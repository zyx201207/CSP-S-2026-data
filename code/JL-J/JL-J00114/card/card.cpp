#include<bits/stdc++.h>
using namespace std;
long long i=1,n,m,a[200100],ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
    }
    long long maxn=a[i];
    for(i=1;i<=n;i++){
        maxn=max(a[i-1],a[i]);
    }
    cout << maxn <<" " << m << " " << m;
    return 0;
}

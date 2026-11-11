#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=1;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int pl=1,pr=1,cur=a[1],dj=0;
    while(pr<=n){
        cur=a[pr];
        if(pl==pr){
            pr++;
            continue;
        }
        dj+=(a[pr]-a[pr-1])*(pr-pl);
        if(dj<=m){
            ans=max(ans,pr-pl+1);
            pr++;
            continue;
        }
        while(dj>m){
            dj-=(cur-a[pl]);
            pl++;
        }
        ans=max(ans,pr-pl+1);
        pr++;
    }
    cout << ans << "\n";
    return 0;
}
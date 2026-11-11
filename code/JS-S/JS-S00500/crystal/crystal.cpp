#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,m,a[MAXN],d[MAXN],q[MAXN];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    d[0]=0;q[0]=0;
    for (int i=1;i<n;i++) {
        d[i]=a[i]-a[i+1];
        d[i]+=d[i-1];
        q[i]=q[i-1]+d[i];
    }
    int len=0,i=1,j=1;
    while(i<=j&&j<=n){
        int now=q[j-1]-d[i-1]*(j-i+1)-q[i-2];
        if (now<=m){
            len++;
            j++;
        } else {
            i++;
            j++;
        }
    }
    cout<<len;
    return 0;
}

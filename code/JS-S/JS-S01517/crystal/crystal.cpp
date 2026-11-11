#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m;
int a[N];
map<int,int> h;
bool check(int mid) {
    int tar=a[mid],sum=0;
    for(int i=1;i<=mid;i++) {
        sum+=tar-a[i];
    }
    if(sum<=m) return 1;
    for(int i=mid+1;i<=n;i++) {
        sum-=tar-a[i-mid];
        sum+=(mid-1)*(a[i]-tar);
        tar=a[i];
        if(sum<=m) return 1;
    }
    return 0;
}
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int Left=1,Right=n,ans;
    while(Left<=Right) {
        int mid=(Left+Right)>>1;
        if(check(mid)) {
            Left=mid+1;
            ans=mid;
        }
        else Right=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
5 5
1 2 4 8 9

*/
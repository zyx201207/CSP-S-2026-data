#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m,a[N+5],lst=0,ans=0,cur=0;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    queue<int> q;
    lst=a[1];
    q.push(1ll);
    ans=1ll;
    for(int i=2;i<=n;i++) {
        cur+=((int)q.size())*(a[i]-lst);
        q.push(i);
        lst=a[i];
        while(!q.empty()&&cur>m) cur-=(lst-a[q.front()]),q.pop();
        ans=max(ans,(int)q.size());
    }
    cout<<ans<<"\n";
    return 0;
}
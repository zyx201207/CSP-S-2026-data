#include<bits/stdc++.h>
#define int long long
using namespace std;
const int L=5e5+10;
int n,m,a[L],k,ans=1;
deque<int> q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    q.push_back(1);
    for(int i=2;i<=n;++i){
        k+=(a[i]-a[q.back()])*q.size();
        while(!q.empty() and k>m){
            k-=a[i]-a[q.front()];
            q.pop_front();
        }
        q.push_back(i);
        ans=max(ans,(long long)q.size());
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N];
deque<int> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    ll sum=0,ans=1;
    for (int i=1;i<=n;i++){
        if (!q.empty()) sum+=(q.size())*(a[i]-a[q.front()]);
        q.push_front(i);
        while(!q.empty() && sum>m) {
            sum-=a[i]-a[q.back()];
            q.pop_back();
        }
        ans=max(ans,ll(q.size()));
        //cout<<q.size()<<" "<<sum<<"\n";
    }
    cout<<ans;
    return 0;
}

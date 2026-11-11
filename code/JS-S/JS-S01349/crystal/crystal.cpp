#include <bits/stdc++.h>
#define  ll long long
#define maxn 500001
using namespace std;
ll n,m,ans=1,a[maxn];
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) pq.push(a[i]-a[i-1]);
    while(m>=0){
        int fr=pq.top();
        pq.pop();
        if(m>=fr) m-=fr,ans++;
        else break;
    }
    cout<<ans;
    return 0;
}

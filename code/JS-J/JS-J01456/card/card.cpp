#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans[N],x,cnt[N],a[N],lst[N],dp[N];

struct node{
int id,val;
};vector<node> d;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lst[a[i]]=i;
    }
    dp[n]=-1;
    for(int i=n-1;i>=1;i--){
        dp[i]=lst[a[i]]+1;
    }
    for(int i=1;i<=n;i++){
        d.push_back({i,dp[i]});
    }
    sort(d.begin(),d.end(),[](node p,node o){return p.val<o.val;});
    for(node i:d){
        cnt[i.id]++;
        if(i.val<=n&&i.val>0){
            cnt[i.val]+=cnt[i.id];
        }
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=cnt[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

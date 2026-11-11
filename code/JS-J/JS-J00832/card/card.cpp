#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
const ll M=3e5+5;
ll n,m;
ll a[N],vis[M];
ll ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        stack<ll> st;
        for(ll j=i;j<=n;j++){
            ll cur=a[j];
            while(!st.empty()&&vis[cur]==1){
                vis[st.top()]=0;
                st.pop();
            }
            st.push(cur);
            vis[cur]=1;
        }
        while(!st.empty()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

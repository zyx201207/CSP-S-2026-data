#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005],cnt[500005];
stack<ll> st;
void card(ll x){
    set<ll> s;
    for(ll i = x; i <= n; i ++){
        if(s.count(a[i]) == 0){
            st.push(a[i]);
            s.insert(a[i]);
        }
        else{
            while((int)(st.top())!=a[i])st.pop();
        }
    }
    while(!st.empty()){
        cnt[st.top()]++;
        st.pop();
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i = 1; i <= n; i ++)cin>>a[i];
    for(ll i = 1; i <= n; i ++){
        card(i);
    }
    for(int i = 1; i <= m; i ++)cout << cnt[i] << ' ';
    return 0;
}

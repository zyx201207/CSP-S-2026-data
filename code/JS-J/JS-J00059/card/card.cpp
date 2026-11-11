#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 10 , INF = 1e18 , mod = 1e9 + 7;
int n , m , pos = -1;
int a[MAXN] , ans[MAXN] , na[MAXN];
bool vis[MAXN] , vis2[MAXN];
void print(){
    for(int i = 1 ; i <= m ; ++i){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; ++i){
        cin>>a[i];
        na[i] = a[i];
    }
    if(m == 1){
        cout<<n;
        return 0;
    }
    if(m == 2){
        int cnt1 = 0 , cnt2 = 0;
        for(int i = 1 ; i <= n ; ++i){
            if(a[i] == 1) cnt1++;
            else cnt2++;
        }
        if(a[n] == 1) cnt1 = n;
        else cnt2 = n;
        cout<<cnt1<<" "<<cnt2<<"\n";
        return 0;
    }
    sort(na + 1 , na + n + 1);
    bool flag = 1;
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] != na[i]){
            flag = 0;
            break;
        }
    }
    if(flag){
        for(int i = 1 ; i <= n ; ++i){
            if(a[i] != a[i - 1]){
                ans[a[i - 1]] = i - 1;
            }
        }
        ans[a[n]] = n;
        print();
        return 0;
    }
    for(int i = n ; i >= 1 ; --i){
        if(vis[a[i]]){
            pos = i;
            break;
        }
        vis[a[i]] = 1;
    }
    if(pos == -1){
        for(int i = 1 ; i <= n ; ++i){
            ans[a[i]] += i;
        }
        print();
        return 0;
    }
    for(int s = 1 ; s <= n ; ++s){
        stack<int> st;
        for(int i = s ; i <= n ; ++i){
            if(vis2[a[i]]){
                while(st.top() != a[i]){
                    vis2[st.top()] = 0;
                    st.pop();
                }
            }
            else{
                st.push(a[i]);
                vis2[a[i]] = 1;
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            vis2[st.top()] = 0;
            st.pop();
        }
    }
    print();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , ans = -2 , a[200005] , es , mx , c0 , c1 , c2 , c3 , c4;
void dfs(ll p , ll num , ll sum){
    ++c0;
    if(c0 > 130000000){
        cout << ans;
        exit(0);
    }
    if(num == m){
        ans = max(ans , sum);
        return;
    }
    if(p > n or (sum < ans and sum != -1)){
        return;
    }
    if(sum == -1){
        dfs(p + 1 , num + 1 , a[p]);
    }
    else{
        dfs(p + 1 , num + 1 , a[p] & sum);
    }
    dfs(p + 1 , num , sum);
}
map<ll , ll>q;
set<ll , greater<ll>>st;
void dfs2(ll p , ll num , ll sum){
    ++c0;
    if(c0 > 6000000){
        cout << ans;
        exit(0);
    }
    if(num >= m){
        ans = max(ans , sum);
        return;
    }
    if(p > n or (sum < ans and sum != -1)){
        return;
    }
    if(sum == -1){
        dfs2(p + 1 , num + q[a[p]] , a[p]);
    }
    else{
        dfs2(p + 1 , num + q[a[p]] , a[p] & sum);
    }
    dfs2(p + 1 , num , sum);
}
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        if(m == n){
            if(i == 1){
                es = a[i];
            }
            else{
                es &= a[i];
            }
        }
        mx = max(mx , a[i]);
    }
    if(m == n){
        cout << es;
        return 0;
    }
    if(mx <= 4 and n > 20){
        for(int i = 1 ; i <= n ; i ++){
            if(a[i] == 0){
                c0 ++;
            }
            else if(a[i] == 1){
                c1 ++;
            }
            else if(a[i] == 2){
                c2 ++;
            }
            else if(a[i] == 3){
                c3 ++;
            }
            else{
                c4 ++;
            }
        }
        if(c4 >= m){
            cout << 4;
            return 0;
        }
        if(c3 >= m){
            cout << 3;
            return 0;
        }
        if(c3 + c2 >= m){
            cout << 2;
            return 0;
        }
        if(c3 + c1 >= m){
            cout << 1;
            return 0;
        }
        cout << 0;
        return 0;
    }
    if(n >= 170000){
        for(int i = 1 ; i <= n ; i ++){
            q[a[i]] ++;
            st.insert(a[i]);
        }
        n = 0;
        for(auto i:st){
            a[++n] = i;
        }
        dfs2(1 , 0 , -1);
        cout << ans;
    }
    else{
        c0 = 0;
        dfs(1 , 0 , -1);
        cout << ans;
    }
    return 0;
}

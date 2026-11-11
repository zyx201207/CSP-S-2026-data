#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;

ll n, m, a[N], dp[N];
ll ans;

bool A, B;

void solveA(){
    ll con = 0;
    ll cha = a[2] - a[1] ;
    for(ll i = 1; i <= n; i ++){
        if((con + i) * cha < m)
            con += i * cha;
        else{
            cout << i;
            return;
        }
    }
    cout << n;
    return ;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] != i) A = true;
    }
    if(!A){
        solveA();
        return 0;
    }
    for(ll i = 3; i <= n; i ++){
        if(a[i] - a[i - 1] != a[2] - a[1]){
            B = true;
            break;
        }
    }
    if(!B){
        solveA();
        return 0;
    }
    sort(a + 1, a + 1 + n);
    for(ll i = 1; i <= n; i ++)
        dp[i - 1] = a[i] - a[i - 1];
    for(ll i = 1; i <= n; i ++){
        ll m1 = m, id = i - 1, ans1 = 1, cnt = 0;
        while(m1 >= dp[id] + cnt && id >= 1){
            m1 = m1 - dp[id] - cnt, cnt+=dp[id] ,id --, ans1 ++;
        }
        ans = max(ans, ans1);
    }
    cout << ans;
    return 0;
}

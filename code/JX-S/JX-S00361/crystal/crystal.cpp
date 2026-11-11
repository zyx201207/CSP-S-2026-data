#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 5e5+100;

ll a[MAXN];
ll M, N;

ll dep[MAXN], SUM[MAXN];

ll ans[MAXN];

void init(){
    cin>> N >> M;
    for(int i=1; i<=N; i++) cin>>a[i];

    sort(a+1, a+1+N);
}

void COUNT(ll n,ll s){

    ll S = s, k = 1;

    for(; S>M; ++k){
        S = s - SUM[k] - (a[n] - a[k])*k;
    }

    ans[n] = n - k+1;

}

ll doo(ll s, ll n, ll k){
    return s - SUM[k] - (a[n] - a[k])*k;
}

void Count(ll n, int s){
    ll S = s, l=0, r = n;

    while(l < r){

        ll mid = (l + r)/2;

        ll num = doo(S, n, mid);

        if(num > M) l = mid+1;
        else r = mid;
    }

    ans[n] = n - l;

}

int main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    for(int i=2; i<=N; i++) a[i] -= a[1];a[1] =0;

    for(int i=1; i<=N; i++) SUM[i] = SUM[i-1] + (a[i] - a[i-1]) * (i-1);

    for(int i=1; i<=N; i++){
        Count(i, SUM[i]);
    }

    ll Ans=-1;

    for(int i=1; i<=N; i++) Ans = max(Ans, ans[i]);

    cout<<Ans;

    return 0;
}

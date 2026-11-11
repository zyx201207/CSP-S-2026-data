#include<bits/stdc++.h>
#define QwQ return 0
#define ll long long
using namespace std;

ll rd();
void rout(ll), out(ll);

const int N = 5e5+5;

ll n, m;
ll a[N];
ll ans;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = rd(), m = rd();
    for(int i=1; i<=n ;i++) a[i] = rd();
    sort(a+1, a+n+1);
    for(ll l=1, r=1, used=0; r<=n; r++){
        used += (r-l)*(a[r]-a[r-1]);
        while(used > m)
            used -= a[r] - a[l++];
        ans = max(ans, r-l+1);
    }
    out(ans);
    QwQ;
}//rp++!




























ll rd(){
    ll x=0, w=1;
    char c=getchar_unlocked();
    while(!isdigit(c)){
        if(c == '-') w=-1;
        c=getchar_unlocked();
    }
    while(isdigit(c)){
        x = (x << 3) + (x << 1) + (c^48);
        c=getchar_unlocked();
    }
    return x*w;
}

void rout(ll x){
    if(x > 9) rout(x/10);
    putchar(x%10^48);
}

void out(ll x){
    if(x < 0) putchar('-'), x = -x;
    rout(x);
}

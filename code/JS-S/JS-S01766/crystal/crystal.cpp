#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> PLL;
const ll MAXN = 100010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n,m,ans = -INF,pos;
ll a[MAXN];
ll bin(ll tar){
    ll sum = -1;
    ll l = 1,r = n;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(a[mid] > tar) r = mid - 1;
        else if(a[mid] <= tar){
            l = mid + 1;
            sum = mid;
        }
    }
    return sum;
}
bool check(ll tar){
    ll sum = 0;
    pos = 0;
    if(bin(tar) == -1) return false;
    else{
        pos = bin(tar);
        for(int i = 1;i <= pos;i++){
            sum += (tar - a[i]);
        }
    }
    if(sum <= m){
        return true;
    }
    else return false;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("crystal.in",'r',stdin);
    freopen("crystal.out",'w',stdout);
    cin>>n>>m;
    ll maxn = -INF,minn = INF;
    for(ll i = 1;i <= n;i++){
        cin>>a[i];
        maxn = max(maxn,a[i]);
        minn = min(minn,a[i]);
    }
    if(n >= 2){
        bool flag = true;
        ll cal = a[2] - a[1];
        for(int i = 2;i <= n;i++){
            if(a[i + 1] - a[i] != cal){
                flag = false;
                break;
            }
        }
        if(flag){
            ll c = m / cal;
            ll num = (-1 + sqrt(1 + 4 * c)) / 2;
            cout<<num;
            return 0;
        }
    }
    sort(a,a + n);
    ll l = minn,r = maxn;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid)){
            ans = max(ans,pos);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<ans;
    return 0;
}

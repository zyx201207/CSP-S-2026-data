#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long ll;
ll n,m;
ll a[N];
struct node{
    int b,cnt;
}f[N];
bool cmp(node x,node y){
    return x.b < y.b;
}
map<ll,int>mp;
int main (){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a+1,a+n+1);
    bool fa = true,fb = true;
    for(int i = 1; i <= n; i++){
        if(a[i]!=i){
            fa = false;
            break;
        }

    }
    for(int i = 2; i <= n-1; i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            fb=false;
            break;
        }
    }
    if(fa){
        ll ans = 1;
        while(ans*(ans-1)/2<=m){
            ans++;
        }
        cout << --ans;
        return 0;
    }
    if(fb){
        ll ans = 1,c = a[2]-a[1];
        while(ans*(ans-1)/2*c<=m)
            ans++;
        cout<<--ans;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        mp[a[i]]++;
    }
    ll idx = 1,pre;
    for(auto it = mp.begin();it!=mp.end();it++){
        if(idx == 1){
            pre = it->first;
        }else{
            f[idx].b = it->first-pre;
            f[idx].cnt = it->second;
            pre = it->first;
        }
        idx++;
    }
    idx--;
    //sort(f+2,f+idx+1,cmp);
    ll ans = 1;
    for(int i = 2; i <= idx;i++){
        if(m>=f[i].b&&f[i].cnt>=1){
            if(m/f[i].b>=f[i].cnt){
                m-=f[i].cnt*f[i].b;
                ans+=f[i].cnt;
            }else{
                m-=m/f[i].b*f[i].b;
                ans+=m/f[i].b;
            }
            /*while(m>=f[i].b&&f[i].cnt>=1){
                m-=f[i].b;
                f[i].cnt--;
                ans++;
            }*/
        }else{
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    return 0;
}//Oct31==Dec25?

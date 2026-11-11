#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005], cha[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    ll ma = -1, mi = INT_MAX;
    bool pd = 1;
    cin >> a[1] >> a[2];
    ll gc = a[2] - a[1];
    for(ll i = 3; i <= n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
        if(a[i] - a[i - 1] != gc) pd = 0;
    }
    //cout << pd << endl;
    if(pd == 1){
        ll s1 = 1 - gc, c1 = gc - 1, js = 0;
        ll s2 = 0, c2 = gc;
        //int x = 0;
        while(1){
            //x++;
            //if(x >= 10){
                //return 0;
            //}
            s1 += c1;
            s2 += c2;
            c1 += gc;
            c2 += gc;
            js++;
            if(m >= s1 && m < s2){
                cout << js;
                //cout << "*****";
                return 0;
            }
            //cout << s2 << " ";
        }
    }
    else{
        ll z = m;
        ll ans = -1;
        for(ll temp = mi; temp <= ma; temp++){
            z = m;
            //cout << "temp=" << temp << endl;
            memset(cha, 0x3f, sizeof(cha));
            for(ll i = 1; i <= n; i++){
                if(temp - a[i] >= 0) cha[i] = temp - a[i];
                //cout << a[i] << " ";
            }
            bool f = 0;
            sort(cha + 1, cha + 1 + n);
            //cout << "cha: ";
            for(ll i = 1; i <= n; i++){
                //cout << cha[i] << " ";
            }
            //cout << endl << "m:";

            for(ll i = 1; i <= n; i++){
                //cout << "i=" << i << " ";
                z -= cha[i];
                if(z < 0 && f == 0){
                    //cout << "answer =" << i - 1;
                    ans = max(i - 1, ans);
                    f = 1;
                }
                //cout << "z=" << z << " ";
            }
            if(!f) {
                cout << n;
                return 0;
            }
            //cout << endl;
        }
        cout << ans;
   }

    return 0;
}

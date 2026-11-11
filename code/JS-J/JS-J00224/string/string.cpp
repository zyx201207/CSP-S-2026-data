#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10,INF = 0x3f3f3f3f;
pair<ll,char> a[N],b[N];
ll tot = 0;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> b[i].first >> b[i].second;
        tot += b[i].first;
    }
    ll cut = (tot + 1) / 2;
    ll tb = 0,tp = 1;
    while(1){
        tb += b[tp].first;
        if(tb >= cut){
            a[tp + 1].first = (tb - cut);
            a[tp].first = (b[tp].first - a[tp + 1].first - (tot % 2 == 1));
            a[tp].second = b[tp].second;
            a[tp + 1].second = b[tp].second;
            break;
        }
        a[tp].first = b[tp].first;
        a[tp].second = b[tp].second;
        tp++;
    }
    tp += 2;
    for(int i = tp;i <= n + 1;i++){
        a[i].first = b[i - 1].first;
        a[i].second = b[i - 1].second;
    }

    /*for(int i = 1;i <= n + 1;i++){
        cout << a[i].first << " " << a[i].second << "\n";
    }*/
    n++;
    ll nt = 0,i = 1,cnt = 0,cun = 0;
    char now;
    while(1){
        nt += a[i].first;
        cun = a[i].first;
        now = a[i].second;
        if(nt >= (tot / 2)){
            ll r = n;
            while(1){
                cun -= a[r].first;
                if(now != a[r].second)cnt += a[r].first;
                if(cun <= 0){
                    a[r].first = (0 - cun);
                    if(now != a[r].second)cnt -= (0 - cun);
                    break;
                }
                r--;
            }
            break;
        }else{
            ll r = n;
            while(1){
                cun -= a[r].first;
                if(now != a[r].second)cnt += a[r].first;
                if(cun <= 0){
                    a[r].first = (0 - cun);
                    if(now != a[r].second)cnt -= (0 - cun);
                    break;
                }
                r--;
            }
            n = r;
        }
        i++;
    }

    cout << cnt;/**/
    return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define pdd pair<double,double>
using ll = long long;
using namespace std;
constexpr int N = 114514 * 5;
ll n,m,a[N],c[N],l,r,maxn=-1;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    sort(a+1,a+n+1);
    if(n<=5000){
        for(int i = 1 ; i <= n ; i++){
            ll ans = 1;
            for(int j = 1 ; j < i ; j++){
                c[j] = abs(a[j]-a[i]);
            }
            l = i - 1,r = i +1;
            ll s = m;
            while(s > 0 && l > 0){
                if(s >= c[l]){
                    ans++;
                    s-=c[l];
                    l--;
                }
                else break;
            }
            maxn = max(maxn,ans);
        }
        cout << maxn << endl;
        return 0;
    }
    else{
        ll h = a[2] - a[1];
        ll g = m/h;
        l = 1;
        g*=2;
        for(l = 1 ; l *(l+1) <= g ; l++){

        }
        if(l>=n)l=n;
        cout << l << endl;
    }
    return 0;
}

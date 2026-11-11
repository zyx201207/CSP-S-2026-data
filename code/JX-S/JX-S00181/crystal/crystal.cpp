#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 7;
ll a[MAXN];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    ll cha = a[2] - a[1];
    bool flag = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] - a[i - 1] != cha) flag = 0;
    }
    if(flag) {
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += i * cha;
            if(sum > m) {
                cout << i << endl;
                return 0;
            }
        }
    }
    else {
    //int ii,jj;
        for(int i = n; i >= 1; i--) {
            ll sum = 0, dj=0;
            for(ll j = i; j >= 0; j--) {
                    //cout << sum - a[j]+ a[i] << " " << m <<"\n";
                    sum += a[i] - a[j];
                if(sum > m) {
                     //cout<<sum<<endl;
                     //cout<<"breaked:"<<i<<" "<<j<<endl;
                    dj = j; break;
                }

                if(j==0) {dj=j;
                //cout<<"breaked:"<<i<<" "<<j<<endl;
                }
            }
            //cout<<"jieshu" << i <<" "<<dj <<" "<< dj - i + 1 <<endl;
            //if(i-dj>ans)ii=i,jj=dj;
            ans = max(ans, i - dj);
        }
        cout << ans << endl;
        //cout << ii << " " << jj;
        //for(int i=jj;i<=ii;i++)cout << a[i] <<endl;
        return 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll a[N],cf[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    bool flag = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] != i){
            flag = 1;
        }
    }
    sort(a + 1,a + n + 1);
    cf[1] = a[2] - a[1];
    for(int i = 1;i <= n;i++){
        cf[i] = cf[i - 1] + a[i] - a[i - 1];
    }
    if(flag == 0){
        ll cnt = 0;
        if(m == 0){
            cout<<1;
            return 0;
        }
        for(int i = 2;i < n;i++){
            ll tmp = cnt + i;
            if(cnt < m && m <= tmp){
                cout<<i;
                return 0;
            }
            cnt = tmp;
        }
        cout<<n;
        return 0;
    }
    flag = 0;
    int cha = cf[2] - cf[1];
    for(int i = 2;i <= n;i++){
        if((cf[i] - cf[i - 1]) != cha){
            flag = 1;
        }
    }
    if(flag == 0){
        ll cnt = 0;
        if(m == 0){
            cout<<1;
            return 0;
        }
        int tmp = m / cha;
        if(tmp <= n * (n - 1) / 2){
            int sum = 1;
            for(int i = 1;i <= n;i++){
                if(tmp >= sum){
                    tmp -= sum;
                    sum++;
                }
                else{
                    cout<<i;
                    return 0;
                }
            }
        }
        else{
            cout<<n;
        }
        return 0;
    }
    if(n == 1){
        cout<<1;
        return 0;
    }
    if(n == 2){
        int tmp = a[2] - a[1];
        if(m < tmp){
            cout<<1;
        }
        else{
            cout<<2;
        }
        return 0;
    }
    if(n == 3){
        int ma = a[2] - a[1];
        int mb = a[3] - a[2];
        if(m >= 2 * mb + ma){
            cout<<3;
            return 0;
        }
        if(m >= ma || m >= mb){
            cout<<2;
            return 0;
        }
        cout<<1;
        return 0;
    }
    if(n == 4){
        int ma = a[2] - a[1];
        int mb = a[3] - a[2];
        int mc = a[4] - a[3];
        if(m >= 3 * mc + 2 * mb + ma){
            cout<<4;
            return 0;
        }
        int cnt = min(2 * mb + ma,2 * mc + mb);
        if(m >= cnt){
            cout<<3;
            return 0;
        }
        if(m >= ma || m >= mb || m >= mc){
            cout<<2;
            return 0;
        }
        cout<<1;
        return 0;
    }
    if(n == 5){
        int ma = a[2] - a[1];
        int mb = a[3] - a[2];
        int mc = a[4] - a[3];
        int md = a[5] - a[4];
        if(m >= 4 * md + 3 * mc + 2 * mb + ma){
            cout<<5;
            return 0;
        }
        int cnt = min(3 * mc + 2 * mb + ma,3 * md + 2 * mc + mb);
        if(m >= cnt){
            cout<<4;
            return 0;
        }
        int tmp = min(2 * md + mc,min(2 * mc + mb,2 * mb + ma));
        if(m >= tmp){
            cout<<3;
            return 0;
        }
        if(m >= ma || m >= mb || m >= mc || m >= md){
            cout<<2;
            return 0;
        }
        cout<<1;
        return 0;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        cnt += cf[n] - cf[i];
    }
    if(m >= cnt){
        cout<<n;
        return 0;
    }
    for(int i = n - 1;i >= 1;i--){
        for(int j = 1;j + i - 1 <= n;j++){
            int cnt = 0;
            int sum = i - 1;
            for(int k = j + i - 1;k >= j;k--){
                cnt += sum * (cf[k] - cf[k - 1]);
                sum--;
            }
            if(m >= cnt){
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}

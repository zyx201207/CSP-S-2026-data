#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, ans = -1;
ll cry[1000005];
int b[4000];

void mp_sort(){
    for(int i = 1; i < n; i++){
        for(int j = n; j > i; j--){
            if(cry[j]<cry[j-1]){
                swap(cry[j],cry[j-1]);
            }
        }
    }
}

void solve(){
    mp_sort();
    for(int i = 1; i < n; i++){
        ll mm = m, cnt = 0;
        for(int j = i; j >= 1; j--){
            if(cry[i]-cry[j] <= mm){
                mm -= cry[i]-cry[j];
                cnt++;
            }
            else break;
        }
        ans = max(ans, cnt);
    }
}

void special_solve(){
    for(int i = 1; i <= n; i++){
        if(cry[i]>1000 || cry[i]<-1000){
            solve();
            return;
        }
        b[cry[i]+1000]++;
    }
    for(int i = 0; i <= 2001; i++){
        ll mm = m, cnt = 0;
        for(int j = i; j >= 0; j--){
            if((i-j)*b[j] <= mm){
                mm -= (i-j)*b[j];
                cnt+=b[j];
            }
            else{
                cnt+=mm/(i-j);
                break;
            }
        }
        ans = max(ans, cnt);
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> cry[i];
    }
    if (n > 100000){
        ll dif = cry[2] - cry[1], flag = 1;
        for(int i = 3; i <= n; i++){
            if(cry[i]-cry[i-1] != dif){
                flag = 0;
                break;
            }
        }
        if(flag){
            dif = abs(dif);
            ll cnt = 1;
            for(; dif*cnt*(cnt+1)/2 <= m; cnt++);
            ans = min(cnt,n);
        }
        else special_solve();
    }
    else solve();
    cout << ans;
    return 0;
}

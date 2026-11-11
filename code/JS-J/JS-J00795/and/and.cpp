#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
bool ok[200003][33];
bool survive[200003];
int tot[33];
signed main(){
    freopen("and.in", "r", stdin);
    freopen("add.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1, x;i <= n;i++){
        cin>>x;
        int bit = 0;
        while(1){
            ok[i][++bit] = (bool)(x % 2);
            if(x % 2)tot[bit]++;
            x /= 2;
            if(x == 0)break;
        }
    }
    int ans = 0, start = 0;
    for(int i = 1;i <= n;i++)survive[i] = 1;
    for(int i = 32;i >= 1;i--){
        if(tot[i] >= m){
            start = i;
            break;
        }
    }
    for(int i = start;i >= 1;i--){
        int cur = 0;
        bool tmp[200003];
        for(int j = 1;j <= n;j++)tmp[j] = survive[j];
        for(int j = 1;j <= n;j++){
            if(!ok[j][i])tmp[j] = 0;
            if(tmp[j])cur++;
        }
        if(cur >= m){
            ans += (1 << (i - 1));
            for(int j = 1;j <= n;j++)survive[j] = tmp[j];
        }
    }
    cout<<ans;
}

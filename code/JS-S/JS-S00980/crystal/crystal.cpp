#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

long long n,m;
long long a[N];
long long pres[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    bool flag1 = true;
    bool flag2 = true;
    long long d = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i) flag1 = false;
        if(i == 2) d = a[i]-a[i-1];
        if(i > 2 && a[i]-a[i-1] != d) flag2 = false;
    }
    if(flag1){
        pres[1] = 0;
        for(int i = 2; i <= n; i++){
            pres[i] = a[i-1] + pres[i-1];
        }
        for(int i = n; i >= 1; i--){
            if(m >= pres[i]){
                cout << i << '\n';
                return 0;
            }
        }
    } else if(flag2){
        pres[1] = 0;
        for(int i = 2; i <= n; i++){
            pres[i] = pres[i-1] + d;
        }
        for(int i = 2; i <= n; i++){
            pres[i] += pres[i-1];
        }
        for(int i = n; i >= 1; i--){
            if(m >= pres[i]){
                cout << i << '\n';
                return 0;
            }
        }
    } else{
        sort(a+1,a+n+1);
        pres[1] = 0;
        for(long long i = 2; i <= n; i++){
            pres[i] = pres[i-1]+(i-1)*(a[i]-a[i-1]);
        }
        for(int i = n; i >= 1; i--){
            if(m >= pres[i]){
                cout << i << '\n';
                return 0;
            }
        }
    }
    return 0;
}

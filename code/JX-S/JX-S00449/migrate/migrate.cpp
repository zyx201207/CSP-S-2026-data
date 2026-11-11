#include<bits/stdc++.h>
using namespace std;

int c , t;
long long n , d;
long long x[2000005];

int mi(int l , int r){
    int cnt = 0 , step = 0;
    int k = l;
    if(x[l+1] - x[l] > d) return 0;
    while(k < r){
        k++;
        if(x[k] - x[l] > d){
            while(x[k] - x[l] > d) k--;
            if(k == l) return 0;
            l = k;
            step++;
        }
        if(k == r) step++;
    }
    return step;
}

int F(int l , int r , int m){
    if(m == 0) return 0;
    if(x[r] - x[l] <= d and m == 1) return 1;
    if(x[r] - x[l] > d and m == 1 or x[r] - x[l] > d and r - l == 1) return 0;
    int k = l+1 , cnt = 0 , step = 0;
    while(x[k] - x[l] <= d){
        step += F(k,r,m-1);
        k++;
    }
    return step;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        int cnt = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        for(int i = 1;i <= n;i++){
            int k = i+1;
            if(x[k] - x[i] > d) continue;
            if(x[n] - x[i] <= d) break;
            while(x[k] - x[i] <= d and k <= n) k++;
            for(int j = k;j <= n;j++){
                int m = mi(i,j);
                if(F(i,j,m) == 2) cnt++;
            }
        }
        cout << cnt << endl;

    }

    return 0;
}

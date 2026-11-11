#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int a[MAXN];
int max_n = 0;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i = 1 ; i <= n ; i++){
        int o;
        cin >>o;
        a[i] = o;
    }
    if(m == n){
        int t = a[1];
        for(int i = 2 ; i <= n ; i++) t = t & a[i];
        cout <<t;
    }
    else if(m == 1){
        for(int i = 1 ; i <= n ; i++){
            if(a[i] > max_n) max_n = a[i];
        }
        cout <<max_n;
    }
    else if(m == 2){
        for(int i = 1 ; i <= n ; i++){
            for(int j = i+1 ; j <= n ; j++){
                int t = a[i] & a[j];
                if(t > max_n) max_n = t;
            }
        }
        cout <<max_n;
    }
    else if(m == n-1){
        int x = a[2];
        for(int j = 3 ; j <= n ; j++) x = x&a[j];
        max_n = x;

        for(int i = 2 ; i <= n ; i++){
            int t = a[1];
            for(int j = 2 ; j <= n ; j++){
                if(j != i) t = t&a[j];
            }
            if(t > max_n) max_n = t;
        }
        cout <<max_n;
    }

    return 0;
}

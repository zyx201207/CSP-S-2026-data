#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    int maxn = 0 , sum = 0;
    for(int i = 1 ; i <= n ; i++){
        maxn = max(maxn , sum);
        if(a[i] ^ a[i] >= maxn){
            sum = a[i] ^ a[i];
        }
    }
    cout <<maxn;
    return 0;
}

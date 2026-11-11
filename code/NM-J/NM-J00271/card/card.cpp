#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N] , s[N] , n , m;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >>n >>m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    a[1] = s[1];
    int l = 1 , r = m;
    a[1] = l , a[2] = r;
    for(int i = 1 ; i <= n ; i++){
        if(a[r] != l){
            s[i] = a[i];
            r++;
        }
        else if(a[r] == l){
            s[i] = s[r] - s[l - 1];
        }
        cout << s[i];
    }
    return 0;
}

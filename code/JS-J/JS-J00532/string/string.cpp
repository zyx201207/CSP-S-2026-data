#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long ans, len, h, b, hp, bp;
int a[N];
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        len += a[i];
    }
    if(n == 1){
        cout << 0;
        return 0;
    }
    h = hp = 1, b = len, bp = n;
    long long mid = len / 2;
    while(h <= mid && hp < bp){
        if(c[hp] == c[bp]){
            if(a[hp] < a[bp]){
                h += a[hp], b -= a[hp];
                a[bp] -= a[hp];
                hp++;
            }
            else if(a[hp] == a[bp]){
                h += a[hp], b -= a[hp];
                a[bp] -= a[hp];
                hp++, bp--;
            }
            else if(a[hp] > a[bp]){
                h += a[bp], b -= a[bp];
                a[hp] -= a[bp];
                bp--;
            }
        }
        else{
            if(a[hp] < a[bp]){
                h += a[hp], b -= a[hp];
                a[bp] -= a[hp];
                ans += a[hp];
                hp++;
            }
            else if(a[hp] == a[bp]){
                h += a[hp], b -= a[hp];
                a[bp] -= a[hp];
                ans += a[hp];
                hp++, bp--;
            }
            else if(a[hp] > a[bp]){
                h += a[bp], b -= a[bp];
                a[hp] -= a[bp];
                ans += a[bp];
                bp--;
            }
        }
    }
    cout << ans;
}

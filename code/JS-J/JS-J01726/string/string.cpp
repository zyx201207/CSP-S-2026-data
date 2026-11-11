#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const int N = 2e5 + 10;

ll n, ans;

struct Node{
    ll x;
    char c;
}a[N];


int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].c;
    }
    for(int i = 1, j = n;i < j;){
        if(a[i].x > a[j].x){
            if(a[i].c != a[j].c){
                ans += a[j].x;
            }
            a[i].x -= a[j].x;
            j--;
        }else if(a[i].x < a[j].x){
            if(a[i].c != a[j].c){
                ans += a[i].x;
            }
            a[j].x -= a[i].x;
            i++;
        }else{
            if(a[i].c != a[j].c){
                ans += a[i].x;
            }
            i++, j--;
        }
    }
    cout << ans << endl;

    return 0;
}
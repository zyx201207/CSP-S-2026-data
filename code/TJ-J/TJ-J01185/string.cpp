#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
const int N = 2e5 + 10;
struct node{
    int a;
    char c;
}xl[N];

signed main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> xl[i].a >> xl[i].c;
    }
    int left = 1, right = n;
    int ans = 0;
    while(left < right){
        int left_a = xl[left].a, right_a = xl[right].a;
        int min_a = min(left_a, right_a);
        char left_c = xl[left].c, right_c = xl[right].c;
        xl[left].a -= min_a, xl[right].a -= min_a;
        if (xl[left].a == 0) left++;
        if (xl[right].a == 0) right--;
        if (left_c != right_c){
            ans += min_a;
        }
    }
    cout << ans;

    return 0;
}


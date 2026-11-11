#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int b = 0;
    int a[n];
    char s[n];
    for(int i = 0;i < n;i++){
        cin >> a[i] >> s[i];
        b += a[i];
    }
    char e[b];
    int k = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < a[i] ;j++){
            e[k] = s[i];
            k++;
        }
    }
    int y = 0;
    if(b % 2 == 0) y = 1;
    int nut = 0;
    for(int i = 0;i <= b / 2;i++){
        if(e[i] != e[b - i]) nut++;
    }
    cout << nut;
}

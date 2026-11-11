#include<bits/stdc++.h>
using namespace std;

int a[2000005], s[2000005];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m * n; i++){
        for(int j = m * n - 1; j >= 0; j++){
            s[i] = a[i] & a[j];
        }
    }
    int q = 0;
    for(int i = 0; i < m * n; i++){
        q = max(s[i], s[i + 1]);
    }
    cout << q;
    return 0;
}

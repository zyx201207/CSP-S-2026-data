#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int s[201000];
    cin >> n >> m;
    for(int i = 0;i <= n;i++){
        cin >> s[i];
    }
    string a[201000];
    int e[201000] = {0};
    for(int i = 0;i <= n;i++){
        string d[50] = {"0"};
        d[i] = s[i] % 2;
        s[i] /= 2;
        e[i]++;
        for(int j = e[i];j >= 0;j--){
            a[i] += d[j];
        }
    }
    bool ans[201000];
    for(int i = 0;i <= n;i++){
        ans[i] = bool(char(a[i]) == char(a[i+1]));
    }
    cout << ans[0];
    return 0;
}

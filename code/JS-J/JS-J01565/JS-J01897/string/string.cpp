#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string s;
    string a, b;
    for(int i = 1;i <= n;i++){
        int q;
        char w;
        cin >> q >> w;
        for(int j = 1;j <= q;j++){
            s += w;
        }
    }
    int half = s.size() / 2;
    int o = s.size();
    for(int i = 0;i <= s.size() - 1;i++){
        if(i < half)a += s[i];
        if(o % 2 == 0&&i >= half)b += s[i];
        if(o % 2 != 0&&i > half)b += s[i];
    }
    for(int i = 0;i <= a.size() - 1;i++){
        if(a[i] != b[i])ans++;
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans = 0,pow2[40] = {1};
string s[200005];
vector <string> v;
void init(){
    for (int i = 1;i < 38;i++){
        pow2[i] = pow2[i - 1] * 2;
    }
    return;
}
string trans(int x){
    string res = "";
    while (x){
        res += char(x % 2 + 48);
        x /= 2;
    }
    while (res.size() < 35){
        res += '0';
    }
    return res;
}
int count(int x){
    int res = 0;
    for (int i = 1;i < n + 1;i++){
        if (s[i][x] == 49){
            res++;
            v.push_back(s[i]);
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    init();
    cin >> n >> m;
    for (int i = 1;i < n + 1;i++){
        cin >> a[i];
        s[i] = trans(a[i]);
    }
    int start = -1;
    for (int i = 33;i > -1;i--){
        if (count(i) > m - 1){
            start = i;
            break;
        }
        v.clear();
    }
    if (start == -1){
        cout << 0;
        return 0;
    }
    for (int i = start;i > -1;i--){
        vector <string> t;
        for (int j = 0;j < v.size();j++){
            t.push_back(v[j]);
        }
        v.clear();
        int res = 0;
        for (int j = 0;j < t.size();j++){
            if (t[j][i] == 49){
                res++;
                v.push_back(t[j]);
            }
        }
        if (res > m - 1){
            ans += pow2[i];
        }
        else{
            v.clear();
            for (int j = 0;j < t.size();j++){
                v.push_back(t[j]);
            }
        }
    }
    cout << ans;
    return 0;
}

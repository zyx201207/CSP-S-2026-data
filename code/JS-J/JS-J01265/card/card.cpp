#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], b[N];
bool vis[N];
string s , s1 = "";
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        s = "";
        for (int j = i; j <= n; j++){
            if (vis[a[j]]) {
                for (int k = 0; k < s.size(); k++){
                    if (s[k]-'0' == a[j]) break;
                    s1 += s[k];
                }
                s = s1;
                s1 = "";
            }
            s = s + char(a[j] + 48);
            for (int j = 0; j <= n; j++) vis[j] = 0;
            for (int j = 0; j < s.size(); j++)
                vis[s[j]-'0'] = 1;
        }
        for (int j = 0; j < s.size(); j++)
            b[s[j]-'0']++, vis[s[j]-'0'] = 0;
    }
    for (int i = 1; i <= m; i++) cout << b[i] << " ";
    return 0;
}

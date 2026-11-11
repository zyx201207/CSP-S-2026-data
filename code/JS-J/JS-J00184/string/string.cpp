#include <bits/stdc++.h>
using namespace std;
long long x[100005];
char ch[505];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string s = "";
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> x[i] >> ch[i];
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= x[i];j++)
            s += ch[i];
    string t = s;
    reverse(s.begin(),s.end());
    if(t == s) cout << 0;
    else
    {
        int cnt = 0;
        for(int i = 0;i < t.size();i++)
            if(s[i] == t[i]) cnt++;
        cout << (t.size() - cnt) / 2;
    }
    return 0;
}

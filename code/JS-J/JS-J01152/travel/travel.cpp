#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
char a;
char b;
string c1;
string s1;
string c2;
string s2;
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline bool row()
{
    return !((a <= 'C') ^ (b <= 'C'));
}
inline bool adj()
{
    if(a > b)
        swap(a,b);
    if(a <= 'B')
        return b == a + 1;
    if(a == 'D')
        return b == 'F';
    return false;
}
int main()
{
    openfile("travel");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c1 >> s1 >> c2 >> s2;
    a = s1.back();
    b = s2.back();
    s1.pop_back();
    s2.pop_back();
    cout << (c1 == c2) << (c1 == c2 && s1 == s2) << (c1 == c2 && s1 == s2 && row()) << (c1 == c2 && s1 == s2 && row() && adj());
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
long long n;
struct zuhe{
    long long cnt;
    char s;
}z[N];
bool ishui(string s)
{
    int a = s[0]-'0';
    for(int i = 1;i < s.size();i++)
    {
        if(s[i]-'0' != a)   return false;
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> z[i].cnt >> z[i].s;
        a+=z[i].cnt*z[i].s;
    }
    bool f = true;//mark
    char sq = z[1].s;
    for(int i = 1;i <= n;i++)
    {
        if(z[i].s == sq)
        {
            f = false;
        }
    }
    if(ishui(a))
    {
        cout << "0";
        return 0;
    }
    if(n == a.size()&&f == true)
    {
        cout << n/2;
        return 0;
    }
    return 0;
}

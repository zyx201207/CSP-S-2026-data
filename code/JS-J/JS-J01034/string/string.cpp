#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
ll n, ans = 0;
ll cnt_front, cnt_back;
ll cnt_f = 0, cnt_b = 0;
ll a[MAXN];
string c[MAXN];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    ll len = 0;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i]>>c[i];
        len = len + a[i];
    }
    cout<<len;
    ll l = 1, r = len;
    cnt_front = 1, cnt_back = n;
    while(l < r)
    {
        string ln = c[cnt_front];
        string rn = c[cnt_back];
        if(ln != rn) ans++;
        cnt_f++, cnt_b++;
        if(cnt_f > a[cnt_front])
        {
            cnt_front--;
            cnt_f = cnt_f - a[cnt_front];
        }
        if(cnt_b > a[cnt_back])
        {
            cnt_back--;
            cnt_b = cnt_b - a[cnt_back];
        }
        l++, r--;
    }
    cout<<ans;
    return 0;
}

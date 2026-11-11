#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll num;
    char data;
};
int n;
ll g,ans;
node *a1,*a2;
ll gcd(ll a,ll b)
{
    if(a == 0) return b;
    gcd(b % a,a);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    a1 = new node[n + 1];
    a2 = new node[n + 1];
    for(int i = 1;i <= n;i++)
    {
        cin >> a1[i].num >> a1[i].data;
        a2[n - i + 1].num = a1[i].num;
        a2[n - i + 1].data = a1[i].data;
    }
    g = a1[1].num;
    for(int i = 1;i <= n;i++) g = gcd(g,a1[i].num);
    for(int i = 1;i <= n;i++)
    {
        a1[i].num /= g;
        a2[i].num /= g;
    }
    int i = 1,j = 1,t;
    while(i <= n && j <= n)
    {
        t = min(a1[i].num,a2[j].num);
        if(a1[i].data != a2[j].data) ans += t;
        a1[i].num -= t;
        a2[j].num -= t;
        if(a1[i].num == 0) i++;
        if(a2[j].num == 0) j++;
    }
    cout << ans * g / 2;
    return 0;
}

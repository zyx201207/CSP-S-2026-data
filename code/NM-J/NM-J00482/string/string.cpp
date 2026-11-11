#include <bits/stdc++.h>
using namespace std;

int n;
struct str
{
    long long ll;
    string s;
};
str abc[200005], cba[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> abc[i].ll >> abc[i].s;
        cba[i].ll = abc[i].ll;
        cba[i].s = abc[i].s;
    }
    int a=1, b=n;
    long long cnt = 0;
    while(a<=n)
    {
        int ls = min(abc[a].ll, cba[b].ll);
        abc[a].ll -= ls;
        cba[b].ll -= ls;
        if(abc[a].s!=cba[b].s)
        {
            cnt += ls;
        }
        if(abc[a].ll==0)
        {
            a++;
        }
        if(cba[b].ll==0)
        {
            b--;
        }
    }
    cout << cnt/2;
    return 0;
}

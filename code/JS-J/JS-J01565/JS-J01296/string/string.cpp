#include<bits/stdc++.h>
using namespace std;

struct node
{
    int n;
    char d;
};

node a[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int f;
    string s;
    cin >> f;
    for (int i=1;i<=f;i++)
    {
        cin >> a[i].n >> a[i].d;
    }
    for (int i=1;i<=f;i++)
    {
        for (int j=1;j<=a[i].n;j++) s = s + a[i].d;
    }
    cout << s;
    int l = s.size()-1, cnt = 0;
    for (int i=0;i<=l;i++)
    {
        if (s[i] != s[l-i])
        {
            cnt ++;
        }
        if (i == l-i || i+1 == l-i)
            break;
    }
    cout << cnt;
    return 0;
}

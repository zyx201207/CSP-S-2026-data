#include<bits/stdc++.h>
using namespace std;
char s[2100000005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n, q = 0;
    long long ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int a;
        char c;
        cin >> a >> c;
        for(int i = q;i < q + a;i++)
        {
            s[i] = c;
        }
        q += a;
    }
    q--;
    int l = 0, r = q;
    while(l <= r)
    {
        int x = s[l] - 'a';
        int y = s[r] - 'a';
        if(x != y)
        {
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bitset<31> bit[200001];
string s[200001];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        int maxx = 0;
        for(int i = 1;i <= n;i ++)
        {
            maxx = max(maxx, a[i]);
        }
        cout << maxx;
        return 0;
    }
    else
    {
        int maxbit = 0;
        for(int i = 1;i <= n;i ++)
        {
            bit[i] = a[i];
            s[i] = bit[i].to_string();
            while(s[i][0] == '0')
            {
                s[i].erase(0, 1);
            }
            maxbit = max(maxbit, int(s[i].size()));
        }
        for(int i = 1;i <= n;i ++)
        {
            while(s[i].size() < maxbit)
            {
                s[i] = "0" + s[i];
            }
        }
        bool f[n + 1];
        for(int i = 0;i <= n;i ++)
        {
            f[i] = 1;
        }
        for(int i = 0;i < maxbit;i ++)
        {
            int cnt = 0;
            for(int j = 1;j <= n;j ++)
            {
                if(f[j])
                {
                    cnt += s[j][i] - '0';
                }
            }

            if(cnt >= m)
            {
                for(int j = 1;j <= n;j ++)
                {
                    if(s[j][i] == '0')
                    {
                        f[j] = 0;
                    }
                }
            }
       }
       int ans = 0x3fffffff;
       for(int i = 1;i <= n;i ++)
       {
           if(f[i])
           {
               ans = ans & a[i];
           }
       }
       cout << ans;
    }
    return 0;
}
/*
0011
1111
0011
1100
1100
11111
00011
00001
01111
00111
cin1:

cout1:

cin2:

cout2:

cin3:

cout3:

cin4:

cout4:

cin5:

cout5:

*/

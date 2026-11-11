#include<bits/stdc++.h>
using namespace std;

int n;
int a[2][200010];
long long ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int t;
        char c;
        cin >> t >> c;
        a[0][i] = t;
        a[1][i] = c - 'a';
    }
    int l = 0,r = n - 1;
    while(l <= r)
    {
        if(a[1][l] == a[1][r])
        {
            if(a[0][l] >= a[0][r])
            {
                a[0][l] -= a[0][r];
                r--;
                if(a[0][l] == 0) l++;
            }
            else
            {
                a[0][r] -= a[0][l];
                l++;
            }
        }
        else
        {
            if(a[0][l] >= a[0][r])
            {
                ans += a[0][r];
                a[0][l] -= a[0][r];
                r--;
                if(a[0][l] == 0) l++;
            }
            else
            {
                ans += a[0][l];
                a[0][r] -= a[0][l];
                l++;
            }
        }
    }
    cout << ans;
    return 0;
}

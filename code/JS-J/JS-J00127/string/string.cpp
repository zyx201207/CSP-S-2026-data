#include<bits/stdc++.h>
using namespace std;
string s;
int a[200010];
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int l = 0;
    cin >> n;
    a[0] = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        cin >> c[i];
        l += a[i];
        a[i] += a[i-1];
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=a[i-1]+1; j<=a[i]; j++)
        {
            if(j <= l/2)
                s[j] = c[i];
            else if(j > (l+1)/2 && j <= l && s[l+1-j] != c[i])
                ans++;
        }
    }
    cout << ans;
    return 0;
}

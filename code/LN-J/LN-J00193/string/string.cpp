#include <bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k = 0,ans = 0,sum = 0;
    string s;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++)
        {
            s += c[i];
        }
    }
    k = (s.size() + 1)/2;
    for(int i = 0;i < k;i++)
    {
        if(s[i] != s[s.size() - 1 - i])
        {
            ans++;
        }
    }
    cout << ans;



    return 0;
}

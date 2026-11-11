#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,x=0;
    string a,b;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int z = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= a[i]; j++)
        {
            s[z] = b[i];
            z++;
        }
    }
    int y = s.size();
    for(int i = 1; i <= y/2; i++)
    {
        if(s[i] != s[y-i+1]) x++;
    }
    cout << x;
    return 0;
}

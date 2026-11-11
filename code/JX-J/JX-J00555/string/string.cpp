#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int num;
        string m;
        cin >> num >> m;
        for(int j = 1;j <= num;j++)
        {
            s += m;
        }
    }
    long long cnt = 0;
    for(int i = 0;i <= s.size()/2-1;i++)
    {
        int sum = s.size()-1;
        if(s[i] != s[sum]) cnt++;
    }
    cout << cnt;
    return 0;
}

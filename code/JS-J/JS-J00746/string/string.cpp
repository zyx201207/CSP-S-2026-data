#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s, s2;
    int n,m,sum;
    char a;
    cin >> n >> s;

    for(int i = 0;i <= n;i++)
    {
        cin >> m >> a;
        for(int j = 0;j < m;j++)
        {
            s += a;
        }
    }s2=s;
    reverse(s2.begin(),s2.end());
    if(s == s2)
    {
        cout << "0";
        return 0;
    }
    for(int i = 0;i <s.size();i++)
    {
        sum++;
    }
    cout << sum/2;
    return 0;
}

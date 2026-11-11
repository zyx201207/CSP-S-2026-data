#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,num=0;
    string s,c;
    cin >> n;
    for (long long i = 1;i <= n;i++)
    {
        cin >> a >> c;
        for (long long i = 1;i <= a;i++)
        {
            s+=c;
        }
    }
    string s2;
    s2=s;
    reverse(s2.begin(),s2.end());
    if (s==s2)
    {

        cout << 0;
        return 0;
    }
    for (long long i = 0;i <= s.length()/2;i++)
    {
        if (s[i]!=s[s.length()-1-i])
        {
            num++;
        }
    }
    cout << num;
    return 0;
}

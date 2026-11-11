#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<char> s;
    long long t,a,m = 0;
    char b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        while(a--) s.push_back(b);
    }
    for(long long i = 0;i < s.size()/2;i++)
        if(s[i] != s[s.size()-i-1]) m++;
    cout << m;
    return 0;
}

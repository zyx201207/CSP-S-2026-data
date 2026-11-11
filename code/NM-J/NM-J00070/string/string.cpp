#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    long long d=0;
    string s,c;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> c;
        while(a)
        {
            s+=c;
            a--;
        }
    }
    int len = s.size();
    for(int i=0;i<len/2;i++)
    {
        if(s[i]==s[n-i])    continue;
        else    d++;
    }
    cout << d;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool h(string q,long long e)
{
    for(int i = 0;i<e/2;i++)
    {
        if(q[i] != q[e-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,c = 0;
    string m;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        int a;
        char b;
        cin >> a >> b;
        c+=a;
        for(int i = 1;i<=a;i++)
        {
            m+=b;
        }
    }
    long long sum = 0;
    for(int i = 0;i<c/2;i++)
    {
        if(h(m,c) == true)
        {
            break;
        }
        if(m[i]!=m[c-1-i])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}

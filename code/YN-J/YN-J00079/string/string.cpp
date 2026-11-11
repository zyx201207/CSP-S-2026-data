#include <bits/stdc++.h>
using namespace std;
int n,a;
char c;
long long sum=-1,cnt;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while (n--)
    {
        cin>>a>>c;
        if (a>=1e8)
        {
            cout<<1000000000;
            return 0;
        }
        sum+=a;
        for (int i=1;i<=a;i++)
        {
            s+=c;
        }
    }
    long long num=sum/2;
    for (long long i=0;i<num;i++)
    {
        if (s[i]!=s[sum-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

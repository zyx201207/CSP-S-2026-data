#include <bits/stdc++.h>
using namespace std;
int n;
string s1="";
long long len;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x;
        char c;
        cin>>x>>c;
        len+=x;
        for(long long i=1;i<=x;i++)
        {
            s1=s1+c;
        }
    }
    long long cnt=0;
    for(long long i=0;i<len/2;i++)
    {
        if(s1[i]!=s1[len-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}

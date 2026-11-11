#include <bits/stdc++.h>
using namespace std;
string m;
int n;
int main()
{
    freopen("string .in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long len=0;
    for(int i=1;i<=n;i++)
    {
        long long a;
        string c;
        cin>>a>>c;
        for(int i=1;i<=a;i++) m+=c;
        len+=a;
    }
    long long sum=0;
    for(long long i=0;i<=len/2-1;i++)
    {
        if(m[len-i]!=m[i]) sum++;
    }
    cout<<sum;
    return 0;
}

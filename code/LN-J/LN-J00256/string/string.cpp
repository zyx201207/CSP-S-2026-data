#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,cnt=0,sum=0;
    string b,c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        sum+=a;
        for(int i=1;i<=a;i++)
        {
            c.append(b);
        }
    }
    for(int i=1;i<=sum/2;i++)
    {
        if(c[i-1]!=c[sum-i])
        {
            c[i-1]=c[sum-i];
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

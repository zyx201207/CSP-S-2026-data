#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[1000000];
    long long n,r=0,h=0,k;
    char a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        cin>>a;
        for(int j=r;j<r+k;j++)
        {
            s[j]=a;
        }
        r+=k;
    }
    for(int i=0;i<r/2;i++)
    {
        if(s[i]!=s[r-1-i])
            h++;
    }
    cout<<h;
    return 0;
}

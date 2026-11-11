#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long k;
        string a="";
        cin>>k>>a;
        while(k--)
        {
            s=s+a;
        }
    }
    long long l=s.size();
    for(int i=0;i<=l/2-1;i++)
    {
        if(s[i]!=s[l-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

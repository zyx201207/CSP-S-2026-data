#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    while(n--)
    {
        char c;
        long long a;
        cin>>a>>c;
        while(a--)s+=c;
    }
    long long m=0;
    for(long long i=0;i<=s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])m++;
    }
    cout<<m;
    return 0;
}

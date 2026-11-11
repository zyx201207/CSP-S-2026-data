#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    while(n--)
    {
        long long m;
        cin>>m;
        char c;
        cin>>c;
        for(long long i=1;i<=m;i++)
        {
            s+=c;
        }
    }
    long long l=s.size();
    long long cnt=0;
    for(long long i=0;i<=l/2-1;i++)
    {
        if(s[i]!=s[l-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
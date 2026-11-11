#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string,out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0;
    string s;
    for(int i=0;i<n;i++)
    {
        long long x;
        char c;
        cin>>x>>c;
        for(int j=0;j<x;j++)
        {
            s+=c;
        }

    }
    for(int j=0;j<s.size()/2;j++)
    {
        if(s[j]!=s[s.size()-j])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector <long long> a;
    vector <string> c;
    vector <string> b;
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long tmp;
        cin>>tmp;
        a.push_back(tmp);
        string tmp2;
        cin>>tmp2;
        c.push_back(tmp2);
    }
    for(long long i=0;i<a.size();i++)
    {
        for(long long j=1;j<=a[i];j++)
        {
            b.push_back(c[i]);
        }
    }
    long long cnt=0;
    for(long long i=0;i<b.size();i++)
    {
        if(b[i]!=b[b.size()-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;
long long pos=0;
map<long long,char>mp;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        char c;
        long long x;
        cin>>x>>c;
        for(int i=1;i<=x;i++)
        {
            pos++;
            mp[pos]=c;
        }
    }
    long long cnt=0;
    for(long long i=1;i<=pos/2;i++)
    {
        if(mp[i]!=mp[pos+1-i])
        {
            cnt++;

        }
    }
    cout<<cnt;
    return 0;
}

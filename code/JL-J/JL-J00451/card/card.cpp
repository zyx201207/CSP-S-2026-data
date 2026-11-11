#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<long long>v;
    long long a,si,s2;
    long long s[200005];
    si=1;s2=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>a;
        for(long long j=1;j<=si;j++)
        {
            if(s[j]==a)
            {
                s2=1;
                break;
            }
        }
        if(s2==0)
        {
            s[si]=a;
            si++;
        }
        for(long long j=0;j<sizeof(v)/sizeof(v[0]);j++)
        {
            if(a==v[j])
            {
                v.clear();
            }
        }
        v.push_back(a);
    }
    si=si-1;
    sort(s,s+si);
    long long b,c;
    if(!v.empty())
    {
        for(int j=1;j<=m;j++)
        {
            b=0;
            for(long long i=0;i<v.size();i++)
            {
                if(v[i]==s[j])
                {
                    b++;
                }
            }
            cout<<b<<" ";
        }
    }
    return 0;
}



































































































































































































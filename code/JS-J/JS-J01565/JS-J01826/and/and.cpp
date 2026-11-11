#include<bits/stdc++.h>
using namespace std;
long long n,m,f;
long long x[200005],b[200005];
string a[200005],ans;
bool cmp(string a,string b)
{
    if(a.size()>b.size())
        return 1;
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1)
    {
        long long ans1=0;
        for(long long i=0;i<n;i++)
        {
            cin>>x[i];
            if(ans1<x[i])
                ans1=x[i];
        }
        cout<<ans1;
        return 0;
    }
    return 0;
}

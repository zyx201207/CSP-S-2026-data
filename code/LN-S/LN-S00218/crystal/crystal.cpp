#include <bits/stdc++.h>
using namespace std;
long long a[600000];
queue<long long>q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long c=1;
    long long d=0;
    long long ans=0;
    q.push(a[0]);
    for(int i=1;i<n;i++)
    {
        long long e=q.back();
        d+=(a[i]-e)*c;
        c++;
        q.push(a[i]);
        if(d<=m)
        {
            ans=max(ans,c);
        }
        else
        {
            while(d>m)
            {
                long long f=q.front();
                q.pop();
                d-=a[i]-f;
                c--;
            }
            ans=max(ans,c);
        }
    }
    cout<<ans;
    return 0;
}

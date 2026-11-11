#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,w,e,s[N],l,r,ans,a[N];
deque<long long> q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m; 
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    for(long long i=1;i<=n;i++)
    {
        a[i]=s[i];
        s[i]+=s[i-1];
    }
    l=1;
    r=1;
    q.push_back(1);
    while(l<=r&&r<=n)
    {
        while(q.size()&&q.front()<l)
        {
            q.pop_front();
        }
        if(q.size()&&(a[q.front()]*(r-l+1))-(s[r]-s[l-1])<=m)
        {
            ans=max(ans,r-l+1);
            r++;
            while(q.size()&&a[q.back()]<=a[r])
            {
                q.pop_back();
            }
            q.push_back(r);
        }
        else
        {
            l++;
        }
    }
    cout<<ans;
    return 0;
}//long long
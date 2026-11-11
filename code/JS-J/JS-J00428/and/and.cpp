#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    unsigned long long ans=0,k=1<<30;
    int n,m,cnt,i,j;
    cin>>n>>m;
    unsigned long long a[n+1];
    int prev[n+1],next[n+1];
    int head=1;
    int b[n+1];
    for(i=1;i<=n;i++)
    {
        b[i]=1;
        cin>>a[i];
        prev[i]=i-1;
        next[i]=i+1;
    }
    for(i=30;i>=0;i--)
    {
        cnt=0;
        for(j=head;j<=n;j=next[j])
        {
            if(((a[j]&k)==k)) cnt++;
        }
        if(cnt>=m)
        {
            ans+=k;
            for(j=head;j<=n;j=next[j])
            {
                if((a[j]&k)==0)
                {
                    next[prev[j]]=next[j];
                    prev[next[j]]=prev[j];
                    if(j==head) head=next[j];
                }
            }
        }
        k>>=1;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;int n,m;
long long num[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    long long a[n+5];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        stack<long long> s;
        bool f[m+1],fl[m+1];
        memset(fl,0,sizeof(fl));
        memset(f,0,sizeof(f));
        for(int j=i-1;j<n;j++)
        {
            if(f[a[j]]==1)
            {
                while(s.top()!=a[j]) f[s.top()]=0,s.pop();
                f[s.top()]=0,s.pop();
            }
            s.push(a[j]);
            f[a[j]]=1;
        }
        while(s.size()>0)
        {
            if(fl[s.top()]==0) num[s.top()]++,fl[s.top()]=1;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<num[i]<<" ";
    return 0;
}

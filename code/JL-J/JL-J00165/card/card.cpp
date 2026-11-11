#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,inf=0x3f3f3f3f;
int n,m,a[N],b[N],l[N],num[N],ans[N];
priority_queue<int>q;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>0;i--)
    {
        b[a[i]]=l[b[a[i]]]=i;
    }
    for(int i=1;i<=m;i++)
        num[i]=inf;
    q.push(0);
    for(int i=n;i>0;i--)
    {
        if(i==q.top())
            q.pop();
        if(i<num[a[i]])
        {
            ans[a[i]]+=i-q.top();
            num[a[i]]=q.top();
        }
        q.push(l[i]);
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,ans;
struct nod
{
    int be,en;
    long long dist;
};
queue<nod> q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long dis=0;
    int l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        dis+=a[n]-a[i];
    }
    q.push({l,r,dis});
    while(!q.empty())
    {
        int ll=q.front().be,rr=q.front().en,di=q.front().dist;
        q.pop();
        long long zc1=a[r]-a[l];
        long long zc2=(r-l)*(a[r]-a[r-1]);
        long long di2=di;
        di-=zc1;
        di2-=zc2;
        if(di<=m||di2<=m)
        {
            cout<<rr-ll;
            break;
        }
        q.push({ll+1,rr,di});
        q.push({ll,rr-1,di2});
    }
}

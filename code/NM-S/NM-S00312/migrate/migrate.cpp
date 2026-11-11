#include<bits/stdc++.h>
using namespace std;
struct l{
    int x,l1;
};
long long d,c,t,n,i,j,a[700010],c[700010],ans=INT_MAX,lu=0;
l o;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=INT_MAX;
        lu=0;
        cin>>n>>d;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(i=2;i<=n;i++)
        {
            c[i]=a[i]-a[i-1];
        }
        queue<l> q;
        q.push({1,0});
        while(!q.empty())
        {
            o=q.front();
            q.pop();
            bool b=0;
            for(i=1;i<=n;i++)
            {
                if(abs(a[i]-o.x)<=d)
                {
                    b=1;
                    q.push({i,o.l1+1});
                }
            }
            if(b==0)
            {
                ans=min(ans,l1);
            }
        }
        while(!q.empty())
        {
            o=q.front();
            q.pop();
            bool b=0;
            for(i=1;i<=n;i++)
            {
                if(abs(a[i]-o.x)<=d)
                {
                    b=1;
                    q.push({i,o.l1+1});
                }
            }
            if(b==0&&ans==l1)
            {
                lu++;
            }
        }
        if(lu==2)
        {
            cout<<1<<endl;
        }
    }
    return 0;
}

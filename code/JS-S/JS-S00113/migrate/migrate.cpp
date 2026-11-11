#include <bits/stdc++.h>
using namespace std;
int n,d,x[2000005],minn=1e9,cnt=1;
void dfs(int y,int s,int p)
{
    if (p==y)
    {
        if (s<minn)
        {
            minn=s;
            cnt=1;
        }
        else if (s==minn)
        {
            cnt++;
        }
        return;
    }
    int c=1;
    while(x[p+c+1]-x[p]<=d && p+c+1<=y)
    {
        c++;
    }
    for (int i=1;i<=c;i++)
    {
        dfs(f,y,s+1,p+i);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,an=0;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for (int i=1;i<n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                minn=1e9;
                dfs(j,0,i);
                if (cnt==2)
                {
                    an++;
                }
            }
        }
        cout<<an<<endl;
    }
    return 0;
}

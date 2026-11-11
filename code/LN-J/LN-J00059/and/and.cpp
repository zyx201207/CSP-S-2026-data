#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200000];
int ans=0,ans1=0;
int cmp(int a,int b)
{
    return a>b;
}
void dfs(int s,int c,int h)
{
    if(s==m)
    {
        ans=max(ans,h);
        return ;
    }
    for(int i=1;i<=m-c;i++)
    {
        dfs(s+1,c+i,h);
        h&=a[c];
        if(i==m-c&&s+1<m)
        {
            return ;
        }
    }

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=1;i<=n;i++)
    {
        ans=a[i];
        dfs(1,i,a[i]);
        ans1=max(ans,ans1);
    }
    cout<<ans1;
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200000];
int ans=0,ans1=0;

int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        ans=a[i];
        int c;
        for(int j=2;j<=m;j++)
        {
            for(int k=j;k<=n;k++)
            {
                ans&=a[k];
                c++;
                if(c==m)
                {
                    ans1=max(ans,ans1);
                    c--;
                }
            }
            if(c==m)
            {
                ans=max(ans,ans1);
                c=0;
            }
        }
    }
    cout<<ans1;
    return 0;
}*/

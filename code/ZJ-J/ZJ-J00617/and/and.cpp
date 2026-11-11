#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mxans=-2147483648;
bool vis[200010];
int dfs(int de,int check)
{
    if(de>m)    return 0;
    if(de==m)
    {
        int veryverytmp=-64837;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)   continue;
            if(veryverytmp==-64837)
            {
                veryverytmp=a[i];
                continue;
            }
            veryverytmp=veryverytmp&a[i];
        }
        return veryverytmp;
    }
    vis[check]=1;
    int verytmp=-2147483648;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)   verytmp=max(verytmp,dfs(de+1,i));
        //cout<<verytmp<<endl<<de<<" "<<check<<endl;
    }
    vis[check]=0;
    return verytmp;
}
int main()
{
    //文件输入输出
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //按题目要求输入内容
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        mxans=max(dfs(1,i),mxans);
    }
    cout<<mxans<<endl;
}

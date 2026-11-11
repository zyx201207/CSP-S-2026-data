#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005]={};
int vit[300005]={};
int cnt=0;
stack<int> q;
void sc(int x)
{
    while(true)
    {
        int s=q.top();
        if(s==x)
            break;
        vit[s]=0;
        q.pop();
        cnt--;
    }
    return ;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        memset(vit,0,sizeof(vit));
        for(int j=i;j<=n;j++)
        {
            if(vit[a[j]]==0)
            {
                cnt++;
                q.push(a[j]);
                vit[a[j]]=1;
            }
            else
            {
                sc(a[j]);
            }
        }
        for(int p=1;p<=cnt;p++)
        {
            int s=q.top();
            ans[s]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}

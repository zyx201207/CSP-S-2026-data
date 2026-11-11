#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005],a[500005];
int b[300005];
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
memset(b,0,sizeof(b));
cin>>n>>m;
for(int i=1;i<=n;i++)
    cin>>a[i];
for(int i=1;i<=n;i++)
{
    queue<int> q;
    memset(b,0,sizeof(b));
    for(int j=i;j<=n;j++)
    {
        int x=a[j];
        if(b[x]>0)
        {
            q.push(x);
            while(q.front()!=x)
            {
                int sum=q.front();
                q.pop();
                q.push(sum);
            }
            b[q.front()]=0;
            q.pop();
            while(q.front()!=x)
            {
                b[q.front()]=0;
                q.pop();
            }
            q.pop();
            q.push(x);
            b[x]=1;
        }
        else
        {
            q.push(x);
            b[x]=1;
        }
    }
    for(int k=1;k<=m;k++)
        if(b[k]==1)
            ans[k]++;
}
for(int i=1;i<=m;i++)
    cout<<ans[i]<<" ";
fclose(stdin);
fclose(stdout);
return 0;
}

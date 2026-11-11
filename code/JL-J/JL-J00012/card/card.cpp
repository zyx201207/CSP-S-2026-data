#include<bits/stdc++.h>
using namespace std;
queue<int> q;
const int MAXN=300005;
int n,m,a[500005],ans[MAXN];
bool flag[MAXN];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            flag[j]=false;
        for(int j=i;j<=n;j++)
        {
            if(flag[a[j]])
            {
                int p=q.front();
                if(p!=a[j])
                {
                    while(q.front()!=a[j])
                    {
                        q.push(q.front());
                        flag[q.front()]=false;
                        q.pop();
                    }
                    while(q.front()!=p)
                    {
                        flag[q.front()]=false;
                        q.pop();
                    }
                }
                else
                    while(!q.empty())
                    {
                        flag[q.front()]=false;
                        q.pop();
                    }
                q.push(a[j]);
                flag[a[j]]=true;
            }
            else
            {
                q.push(a[j]);
                flag[a[j]]=true;
            }
        }
        for(int j=1;j<=m;j++)
            if(flag[j])
                ans[j]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

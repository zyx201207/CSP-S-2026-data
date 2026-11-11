#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],sum[500005],cnt[1000005];
stack<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
            cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(sum,0,sizeof(sum));
        for(int j=i;j<=n;j++)
        {
            q.push(a[j]);
            sum[a[j]]++;
            if(sum[a[j]]==2)
            {
                bool d=false;
                while(!q.empty())
                {

                    if(q.top()==a[j]&&d==true)
                    {
                        q.pop();
                        break;
                    }
                    if(q.top()==a[j]&&d==false)
                        d=true;
                    sum[q.top()]--;
                    q.pop();
                }
                sum[a[j]]=1;
                q.push(a[j]);
            }


        }
        while(!q.empty())
        {
            cnt[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=n;i++)
    {

        if(cnt[i]!=0)
        {

            cout<<cnt[i]<<" ";
        }
    }
}

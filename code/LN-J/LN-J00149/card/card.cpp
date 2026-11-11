#include <bits/stdc++.h>
using namespace std;
stack<int> p;
int a[1000000];
int n,m;
bool vis[3];
int cnt1=0,cnt2=0;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(!(p.empty()))
            {
                int c=a[j-1];
                p.push(a[j]);
                if(a[j]==c)
                {
                    p.pop();
                }
                else
                {
                    p.pop();
                    p.pop();
                }
            }
            else
            {
                p.push(a[j]);
            }
        }
        vis[1]=false;
        vis[2]=false;
        for(int j=1;j<=p.size();j++)
        {
            if(p[j]==1&&vis[1]==false)
            {
                cnt1++;
                vis[1]=true;
            }
            if(p[j]==2&&vis[2]==false)
            {
                cnt1++;
                vis[2]=true;
            }
            if(vis[1]&&vis[2])
            {
                break;
            }
        }
    }
    cout<<cnt1<<" "<<cnt2;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n,m;
int cd[500005],cnt[500005],gcnt[500005],last[500005];
bool flag[500005];
int game[500005];
void process(int x)
{
    int t=1;
    for(int i=x;i<=n;i++)
    {
        if(gcnt[cd[i]]==0)
        {
            game[t]=cd[i];
            gcnt[cd[i]]=t;
            t++;
        }
        if(gcnt[cd[i]]!=0)
        {
            for(int j=gcnt[cd[i]]+1;j<=t-1;j++)
            {
                gcnt[game[j]]=0;game[j]=0;t--;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(flag[game[i]]==0)
        {
            cnt[game[i]]++;
            flag[game[i]]=1;
        }
    }
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        game[i]=0;gcnt[i]=0;flag[i]=0;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>cd[i];
    if(n>500&&n<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            last[cd[i]]=i;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<last[i]<<" ";
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            init();
            process(i);
            //for(int i=1;i<=n;i++)
            //    cout<<game[i]<<" ";
            //cout<<endl;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<cnt[i]<<" ";
        }
    }
    return 0;
}

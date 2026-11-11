#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010];
int num[1000010];

void play(int i)
{
    int p[1000010]={};
    int step[1000010]={};
    int len=0;
    for(int k=i;k<=n;k++)
    {
        if(p[a[k]]==0)
        {
            len++;
            p[a[k]]=len;
            step[len]=a[k];
        }
        else
        {
            for(int j=p[a[k]]+1;j<=len;j++)
            {
                p[step[j]]=0;
                step[j]=0;
            }
            len=p[a[k]];
        }
    }
    for(int k=1;k<=len;k++)
    {
        num[step[k]]++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) play(i);
    for(int i=1;i<=m;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}

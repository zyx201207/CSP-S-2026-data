#include<bits/stdc++.h>
using namespace std;
int wz[300050];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int sum[300050],srt[300050],stck[300050];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) scanf("%d",&srt[i]);
    for(int i=0;i<n;i++)
    {
        int top=0;
        for(int j=i;j<n;j++)
        {
            int k=wz[srt[j]];
            if(k==0)
            {
                stck[++top]=srt[j];
                wz[srt[j]]=top;
            }
            else
            {
                if(k<=top && stck[k]==srt[j]) top=k;
                else
                {
                    stck[++top]=srt[j];
                    wz[srt[j]]=top;
                }
            }
        }
        for(int j=1;j<=top;j++) sum[stck[j]]++;
    }
    for(int i=1;i<=m;i++) printf("%d ",sum[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m;
int st[500005],top=0;
int a[500005];
int cnt[300005]={};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)//game
    {
        for(int j=i;j<=n;j++)//hand
        {
            for(int k=1;k<=top;k++)//table
            {
                if(st[k]==a[j])
                {
                    top=k-1;
                    break;
                }
            }
            top++;
            st[top]=a[j];
        }
        for(int j=1;j<=top;j++)
        {
            cnt[st[j]]++;
        }
        top=0;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int temp[500005];
int cnt[300005];
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
        int top=1;
        for(int j=i;j<=n;j++)
        {
            int flag=-1;
            for(int k=1;k<top;k++)
            {
                if(temp[k]==a[j])
                {
                    flag=k;
                    break;
                }
            }
            if(flag!=-1)
            {
                top=flag+1;
            }
            else
            {
                temp[top]=a[j];
                top++;
            }
        }
        for(int i=1;i<top;i++)
        {
            cnt[temp[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}

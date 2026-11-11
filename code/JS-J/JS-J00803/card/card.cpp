#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],zc;
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
        int sta[500005],b[300005],top=0;
        for(int j=i;j<=n;j++)
        {
            if(!b[a[j]])
            {
                sta[++top]=a[j];
                b[a[j]]++;
                zc++;
            }
            else
            {
                while(sta[top]!=a[j])
                {
                    b[sta[top]]--;
                    zc--;
                    top--;
                }
            }
        }
        for(int j=1;j<=m;j++)
            ans[i]+=b[i];
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        int s[500005],last=0;
        //memset(s,0,500005);
        for(int j=1;j<=i;j++)
        {
            for(int k=1;k<=j;k++)
                if(a[j]==s[k])
                {
                    for(int l=k;;l++)
                    {
                        s[l]=0;
                        if(s[l+1]==0)
                            break;
                    }
                    last=k;
                    break;
                }
            s[last]=a[j];
            last++;
        }
        for(int j=1;j<=last;j++)
        {
            ans[s[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500000],ans[500000]={0},cnt=0,tmp=1,x=0,y=0;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int l=0;l<n;l++)
    {
        cout<<x<<' ';
        for(int k=0;k<=n;k++)
        {
            if(k>0&&y==tmp)
            {
                x++;
            }
            tmp++;
            for(int i=0;i<n;i++)
            {
                if(a[i]==a[i+1])
                {
                    cnt++;
                    for(int j=0;j<n-i;i++)
                    {
                        a[j]=a[i+j];
                    }
                    i=0;
                }
                y=a[i];
            }
        }

    }
}

#include<bits/stdc++.h>
using namespace std;
int arr[5005];
bool cnt[5005][3005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        int brr[5005];
        for(int j=1;j<=n;j++)
        {
            brr[j]=arr[j];
        }
        for(int j=i;j<=n;j++)
        {
            bool flag=false;
            for(int k=i;k<=n;k++)
            {
                if(brr[k]==brr[j])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                for(int k=i;k<j;k++)
                {
                    if(brr[k]==brr[j])
                    {
                        brr[k]=0;
                    }
                }
                for(int k=j+1;k<=n;k++)
                {
                    brr[k]=0;
                }
                brr[n+1]=brr[j];
                brr[j]=0;
            }
            else
            {
                brr[n+1]=brr[j];
                brr[j]=0;
            }
        }
        for(int j=1;j<=n+1;j++)
        {
            cnt[i][brr[j]]=true;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int cnt2=0;
        for(int j=1;j<=n;j++)
        {
            cnt2+=cnt[j][i];
        }
        cout<<cnt2<<" ";
    }
    return 0;
}

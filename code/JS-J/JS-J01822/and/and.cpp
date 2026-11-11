#include<bits/stdc++.h>
using namespace std;
long long  arr[200007];
long long  mm[2000007];
int main()
{
    int n,m;
    cin>>n>>m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i = 1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j= 1;;j++)
        {
            int num = pow(2,j);
            int fw = 0;
            if(arr[j] == num-1)
            {
                for(int k = 1;k<=j;k++)
                {
                    arr[i] = fw*10+pow(10,k-1);
                }
            }
        }
    }
    int k = 1;
    for(int i = 1;i<=n;i++)
    {
        long long maxa = -999000099;
        for(int j = i;j<=n;j++)
        {
            if(arr[j]>maxa&&m>0)
            {
                maxa = arr[j];
                mm[k] = arr[j];
                k++;
                m--;
                arr[j] = 0;
            }
        }
    }
    long long minn = 999999999;
    for(int i = 1;i<=k;i++)
    {
        minn = min(minn,arr[i]);
    }
    cout<<minn;
    return 0;
}

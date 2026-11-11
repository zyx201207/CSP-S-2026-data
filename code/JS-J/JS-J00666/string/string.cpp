#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long arr[200005];
long long sum[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i]>>c[i];
        sum[i]=sum[i-1]+arr[i];
    }
    long long cnt=0;
    for(long long i=1,j=sum[n];i<=sum[n],j>i;i++,j--)
    {
        char a,b;
        for(int k=1;k<=n;k++)
        {
            if(i>sum[k-1])
            {
                a=c[k];
                break;
            }
        }
        for(int k=n-1;k>=1;k--)
        {
            if(j<=sum[k+1])
            {
                b=c[k];
                break;
            }
        }
        cnt+=(a!=b);
    }
    cout<<cnt<<endl;
    return 0;
}

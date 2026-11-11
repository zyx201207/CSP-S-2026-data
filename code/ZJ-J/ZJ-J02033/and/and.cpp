#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int a[200005],b[200005],ans[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans[i]=1;
    }
    for(int i=30;i>=0;i--)
    {
        //cout<<i<<endl;
        memset(b,0,sizeof(b));
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            if(ans[j]==0)continue;
            if((a[j]>>i)&1)
            {
                sum++;
                b[j]=1;
                //cout<<j<<" ";
            }
        }
        //cout<<endl;
        if(sum==m)
        {
            for(int i=1;i<=n;i++)
            {
                ans[i]=b[i];
            }
            break;
        }
        else if(sum>m)
        {
            for(int i=1;i<=n;i++)
            {
                ans[i]=b[i];
            }
        }
    }
    int result=-1;
    for(int i=1;i<=n;i++)
    {
        if(ans[i])
        {
            if(result==-1)
            {
                result=a[i];
            }
            else
            {
                result&=a[i];
            }
        }
    }
    cout<<result<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

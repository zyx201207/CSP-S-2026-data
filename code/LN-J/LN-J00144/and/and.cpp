#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[200001][31],flag[200001],c[200001],b[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,y=2147483647,z;
        cin>>x;
        flag[i]=1;
        z=x;
        for(int j=30;j>=0;j--)
        {
            y-=b[j];
            x&=y;
            if(x!=z)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }
            z=x;
        }
    }
    for(int j=30;j>=0;j--)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(flag[i])
            {
                if(a[i][j]==1)
                {
                    c[i]=1;
                    cnt++;
                }
                else
                {
                    c[i]=0;
                }
            }
        }
        if(cnt>=m)
        {
            ans+=b[j];
            for(int i=0;i<n;i++)
            {
                if(c[i]==0)
                {
                    flag[i]=0;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int jz[200005][45],flag[200005],ans[45];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        long long t=a[i],cnt=0;
        while(t>0)
        {
            cnt++;
            if(t%2==1)
            {
                jz[i][cnt]=1;
            }
            t/=2;
        }
    }
    for(int i=35;i>=1;i--)
    {
        long long cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(flag[j]==0&&jz[j][i]==1)
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
            ans[i]=1;
            for(int j=1;j<=n;j++)
            {
                if(jz[j][i]==0)
                {
                    flag[j]=1;
                }
            }
        }
    }
    long long jc=1,num=0;
    for(int i=1;i<=35;i++)
    {
        if(ans[i]&1) num+=jc;
        jc*=2;
    }
    cout<<num;
    return 0;
}

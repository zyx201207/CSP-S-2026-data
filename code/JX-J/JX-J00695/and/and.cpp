#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200010],f[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    //memset(a,-1,sizeof a);
    int ans=0;
    for(int k=1;k<=n;k++)
    {
        int last=a[k];
        for(int i=1;i<=m;i++)//m
        {
            int maxx=0;
                for(int i=1;i<=n;i++)
                {
                    maxx=max(maxx,last&a[i]);
                }
                last=maxx;
                for(int i=1;i<=n;i++)
                {
                    if(a[i]==maxx)
                    {
                        a[i]=0;
                        break;
                    }
                }
        }
        ans=max(ans,last);
    }
    cout<<ans;
    return 0;
}

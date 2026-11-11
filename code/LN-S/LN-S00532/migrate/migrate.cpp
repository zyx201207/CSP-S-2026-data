#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int b[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(a[1]<0)
        {
            int ad=abs(a[1]);
            for(int i=1;i<=n;i++)
            {
                a[i]+=ad;
            }
        }
        else if(a[1]>0)
        {
            int ad=a[1];
            for(int i=1;i<=n;i++)
            {
                a[i]-=ad;
            }
        }
        for(int i=1;i<=n;i++)
        {
            b[a[i]]=1;
        }
        int num=0;
        for(int i=0;i<d;i++)
        {
            if(b[i]==1)
            {
                num++;
            }
        }
        int dl=2*num-2;
        int dl2=dl*(a[2]-a[1])-2;
        int l=a[n];
        int ans=(l-dl2+1)/(a[2]-a[1]+1);
        cout<<ans<<endl;
    }
    return 0;
}

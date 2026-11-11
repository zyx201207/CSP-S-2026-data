#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c[500050],ans,q[500050],qz[500050];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    cin>>c[i];
    sort(c+1,c+a+1);
    for(int i=2;i<=a;i++)
        qz[i]=c[i]-c[i-1];
    q[2]=c[2]-c[1],q[1]=0;
    for(int i=3;i<=a;i++)
        q[i]=(c[i]-c[i-1])*(i-1)+q[i-1];
    for(int i=2;i<=a;i++)
    {
        int l=1,y=i;
        while(l<=y)
        {
            int zj=(l+y)/2;
            int sj=0;
            if(zj!=1)
            sj=(zj-1)*(c[i]-c[zj])+q[zj];
            if(b>=q[i]-sj)
            {
                y=zj-1;
                if(ans<i-zj+1)
                    ans=i-zj+1;
            }
            else l=zj+1;
        }
    }
    cout<<ans;
}

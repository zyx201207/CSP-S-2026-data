#include<bits/stdc++.h>
using namespace std;
int c,t,x[5005],xd[5006];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(),cin.tie(),cout.tie();
    cin>>c>>t;
    xd[0]=0;
    for(int iii=1;iii<=t;iii++)
    {
        for(int ii=1;ii<=5005;ii++)
        {
            x[ii]=-1;
            xd[ii]=-1;
        }
        int n,d,ans=0;
        cin>>n>>d;
        int num=0;
        for(int i=2;i<=n;i++)
        {
            if(x[i]-x[i-1]>d)
            {
                num++;
                xd[num]=i;
            }
        }
        if(num>0)
        {
            int start=1;
            while(xd[start]<=xd[num])
            {
                int can=0;
                for(int i=xd[start-1]+1;i<=xd[start]-2;i++)
                {
                    for(int j=xd[start-1]+3;j<=xd[start];j++)
                    {
                        if(x[j]-x[i]<=d)can++;
                        if(can>1)break;
                    }
                    if(can>1)break;
                }
                if(can==1)ans++;
                start++;
            }
        }
        else
        {
                int can=0;
                for(int in=1;in<=n-2;in++)
                {
                    for(int jn=3;jn<=n;jn++)
                    {
                        for(int i=in;i<=jn-2;i++)
                        {
                            for(int j=in+2;j<=jn;j++)
                            {
                                if(x[j]-x[i]<=d)can++;
                                if(can>1)break;
                            }
                            if(can>1)break;
                        }
                        if(can==1)ans++;
                    }

                }

        }
        cout<<ans<<endl;
    }
    return 0;
}

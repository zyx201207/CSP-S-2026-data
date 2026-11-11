#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,k;
long long x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
            cin>>x[i];
        if(n<=3)
        {
            cout<<0<<endl;
            continue;
        }
        if(n==4)
        {
            if(x[3]-x[1]<=d and x[4]-x[3]<=d and x[2]-x[1]<=d and x[4]-x[2]<=d)
                cout<<1;
            else
                cout<<0;
            continue;
        }
        if(n==5)
        {
            int ans=0,o,p,q;
            if(x[3]-x[1]<=d and x[4]-x[3]<=d and x[2]-x[1]<=d and x[4]-x[2]<=d)
                ans=ans+1;
            if(x[4]-x[2]<=d and x[5]-x[4]<=d and x[3]-x[2]<=d and x[5]-x[3]<=d)
                ans=ans+1;

            if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[4]-x[1]>d or x[5]-x[4]>d))
                ans=ans+1;
            else if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[4]-x[1]<=d and x[5]-x[4]<=d and(x[3]-x[1]>d or x[5]-x[3]>d))
                ans=ans+1;
            else if(x[4]-x[1]<=d and x[5]-x[4]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[2]-x[1]>d or x[5]-x[2]>d))
                ans=ans+1;
            else if(x[3]-x[1]<=d and x[4]-x[3]<=d and x[5]-x[4]<=d)
                o=1;
            else if(x[2]-x[1]<=d and x[4]-x[2]<=d and x[5]-x[4]<=d)
                p=1;
            else if(x[2]-x[1]<=d and x[3]-x[2]<=d and x[5]-x[3]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            cout<<ans<<endl;
            continue;
        }
        if(n==6)
        {
            int ans=0,o,p,q;
            for(int i=1;i<=3;i++)
            {
                if(x[i+2]-x[i]<=d and x[i+3]-x[i+2]<=d and x[i+1]-x[i]<=d and x[i+3]-x[i+1]<=d)
                ans=ans+1;
            }
            if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[4]-x[1]>d or x[5]-x[4]>d))
                ans=ans+1;
            else if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[4]-x[1]<=d and x[5]-x[4]<=d and(x[3]-x[1]>d or x[5]-x[3]>d))
                ans=ans+1;
            else if(x[4]-x[1]<=d and x[5]-x[4]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[2]-x[1]>d or x[5]-x[2]>d))
                ans=ans+1;
            else if(x[3]-x[1]<=d and x[4]-x[3]<=d and x[5]-x[4]<=d)
                o=1;
            else if(x[2]-x[1]<=d and x[4]-x[2]<=d and x[5]-x[4]<=d)
                p=1;
            else if(x[2]-x[1]<=d and x[3]-x[2]<=d and x[5]-x[3]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            o=0,p=0,q=0;

            if(x[3]-x[2]<=d and x[6]-x[3]<=d and x[4]-x[2]<=d and x[6]-x[4]<=d and(x[5]-x[2]>d or x[6]-x[5]>d))
                ans=ans+1;
            else if(x[3]-x[2]<=d and x[6]-x[3]<=d and x[5]-x[2]<=d and x[6]-x[5]<=d and(x[4]-x[2]>d or x[6]-x[4]>d))
                ans=ans+1;
            else if(x[5]-x[2]<=d and x[6]-x[5]<=d and x[4]-x[2]<=d and x[6]-x[4]<=d and(x[3]-x[2]>d or x[6]-x[3]>d))
                ans=ans+1;
            else if(x[4]-x[2]<=d and x[5]-x[4]<=d and x[6]-x[5]<=d)
                o=1;
            else if(x[3]-x[2]<=d and x[5]-x[3]<=d and x[6]-x[5]<=d)
                p=1;
            else if(x[3]-x[2]<=d and x[4]-x[3]<=d and x[6]-x[4]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            int f=0;
            for(int i=2;i<=5;i++)
            {
                if(x[i]-x[1]<=d and x[6]-x[i]<=d)
                    f++;
            }
            if(f==2)
                ans=ans+1;
            else
            {
                f=0;
                for(int i=2;i<=5;i++)
                {
                    for(int j=i+1;j<=6;j++)
                    {
                        if(x[i]-x[1]<=d and x[6]-x[j]<=d and x[j]-x[i]<=d)
                            f++;
                    }
                }
                if(f==2)
                    ans=ans+1;
                else
                {
                    f=0;
                    for(int i=2;i<=4;i++)
                    {
                        for(int j=i+1;j<=5;j++)
                        {
                            for(k=j+1;k<=6;k++)
                            {
                                if(x[i]-x[1]<=d and x[6]-x[k]<=d and x[j]-x[i]<=d and x[k]-x[j]<=d)
                                    f++;
                            }
                        }
                    }
                    if(f==2)
                        ans=ans+1;
                }
            }

            cout<<ans;
            continue;
        }
        if(n==7)
        {
            int ans=0,o,p,q;
            for(int i=1;i<=4;i++)
            {
                if(x[i+2]-x[i]<=d and x[i+3]-x[i+2]<=d and x[i+1]-x[i]<=d and x[i+3]-x[i+1]<=d)
                ans=ans+1;
            }
            if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[4]-x[1]>d or x[5]-x[4]>d))
                ans=ans+1;
            else if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[4]-x[1]<=d and x[5]-x[4]<=d and(x[3]-x[1]>d or x[5]-x[3]>d))
                ans=ans+1;
            else if(x[4]-x[1]<=d and x[5]-x[4]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[2]-x[1]>d or x[5]-x[2]>d))
                ans=ans+1;
            else if(x[3]-x[1]<=d and x[4]-x[3]<=d and x[5]-x[4]<=d)
                o=1;
            else if(x[2]-x[1]<=d and x[4]-x[2]<=d and x[5]-x[4]<=d)
                p=1;
            else if(x[2]-x[1]<=d and x[3]-x[2]<=d and x[5]-x[3]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            o=0,p=0,q=0;

            if(x[3]-x[2]<=d and x[6]-x[3]<=d and x[4]-x[2]<=d and x[6]-x[4]<=d and(x[5]-x[2]>d or x[6]-x[5]>d))
                ans=ans+1;
            else if(x[3]-x[2]<=d and x[6]-x[3]<=d and x[5]-x[2]<=d and x[6]-x[5]<=d and(x[4]-x[2]>d or x[6]-x[4]>d))
                ans=ans+1;
            else if(x[5]-x[2]<=d and x[6]-x[5]<=d and x[4]-x[2]<=d and x[6]-x[4]<=d and(x[3]-x[2]>d or x[6]-x[3]>d))
                ans=ans+1;
            else if(x[4]-x[2]<=d and x[5]-x[4]<=d and x[6]-x[5]<=d)
                o=1;
            else if(x[3]-x[2]<=d and x[5]-x[3]<=d and x[6]-x[5]<=d)
                p=1;
            else if(x[3]-x[2]<=d and x[4]-x[3]<=d and x[6]-x[4]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            o=0,p=0,q=0;

            if(x[4]-x[3]<=d and x[7]-x[4]<=d and x[5]-x[3]<=d and x[7]-x[5]<=d and(x[6]-x[3]>d or x[7]-x[6]>d))
                ans=ans+1;
            else if(x[4]-x[3]<=d and x[7]-x[4]<=d and x[6]-x[3]<=d and x[7]-x[6]<=d and(x[5]-x[3]>d or x[7]-x[5]>d))
                ans=ans+1;
            else if(x[6]-x[3]<=d and x[7]-x[6]<=d and x[5]-x[3]<=d and x[7]-x[5]<=d and(x[4]-x[3]>d or x[7]-x[4]>d))
                ans=ans+1;
            else if(x[5]-x[3]<=d and x[6]-x[5]<=d and x[7]-x[6]<=d)
                o=1;
            else if(x[4]-x[3]<=d and x[6]-x[4]<=d and x[7]-x[6]<=d)
                p=1;
            else if(x[4]-x[3]<=d and x[5]-x[4]<=d and x[7]-x[5]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;

            int f=0;
            for(int i=2;i<=5;i++)
            {
                if(x[i]-x[1]<=d and x[6]-x[i]<=d)
                    f++;
            }
            if(f==2)
                ans=ans+1;
            else
            {
                f=0;
                for(int i=2;i<=5;i++)
                {
                    for(int j=i+1;j<=6;j++)
                    {
                        if(x[i]-x[1]<=d and x[6]-x[j]<=d and x[j]-x[i]<=d)
                            f++;
                    }
                }
                if(f==2)
                    ans=ans+1;
                else
                {
                    f=0;
                    for(int i=2;i<=4;i++)
                    {
                        for(int j=i+1;j<=5;j++)
                        {
                            for(k=j+1;k<=6;k++)
                            {
                                if(x[i]-x[1]<=d and x[6]-x[k]<=d and x[j]-x[i]<=d and x[k]-x[j]<=d)
                                    f++;
                            }
                        }
                    }
                    if(f==2)
                        ans=ans+1;
                }
            }
            f=0;
            for(int i=3;i<=6;i++)
            {
                if(x[i]-x[1]<=d and x[7]-x[i]<=d)
                    f++;
            }
            if(f==2)
                ans=ans+1;
            else
            {
                f=0;
                for(int i=3;i<=6;i++)
                {
                    for(int j=i+1;j<=7;j++)
                    {
                        if(x[i]-x[1]<=d and x[7]-x[j]<=d and x[j]-x[i]<=d)
                            f++;
                    }
                }
                if(f==2)
                    ans=ans+1;
                else
                {
                    f=0;
                    for(int i=3;i<=5;i++)
                    {
                        for(int j=i+1;j<=6;j++)
                        {
                            for(k=j+1;k<=7;k++)
                            {
                                if(x[i]-x[1]<=d and x[7]-x[k]<=d and x[j]-x[i]<=d and x[k]-x[j]<=d)
                                    f++;
                            }
                        }
                    }
                    if(f==2)
                        ans=ans+1;
                }
                cout<<ans;
                continue;
            }

        }
        if(n==8)
        {
            int f=0,ans=0;
            for(int i=2;i<=5;i++)
            {
                if(x[i]-x[1]<=d and x[6]-x[i]<=d)
                    f++;
            }
            if(f==2)
                ans=ans+1;
            else
            {
                f=0;
                for(int i=2;i<=5;i++)
                {
                    for(int j=i+1;j<=6;j++)
                    {
                        if(x[i]-x[1]<=d and x[6]-x[j]<=d and x[j]-x[i]<=d)
                            f++;
                    }
                }
                if(f==2)
                    ans=ans+1;
                else
                {
                    f=0;
                    for(int i=2;i<=4;i++)
                    {
                        for(int j=i+1;j<=5;j++)
                        {
                            for(k=j+1;k<=6;k++)
                            {
                                if(x[i]-x[1]<=d and x[6]-x[k]<=d and x[j]-x[i]<=d and x[k]-x[j]<=d)
                                    f++;
                            }
                        }
                    }
                    if(f==2)
                        ans=ans+1;
                }

            f=0;
            for(int i=3;i<=6;i++)
            {
                if(x[i]-x[1]<=d and x[7]-x[i]<=d)
                    f++;
            }
            if(f==2)
                ans=ans+1;
            else
            {
                f=0;
                for(int i=3;i<=6;i++)
                {
                    for(int j=i+1;j<=7;j++)
                    {
                        if(x[i]-x[1]<=d and x[7]-x[j]<=d and x[j]-x[i]<=d)
                            f++;
                    }
                }
                if(f==2)
                    ans=ans+1;
                else
                {
                    f=0;
                    for(int i=3;i<=5;i++)
                    {
                        for(int j=i+1;j<=6;j++)
                        {
                            for(k=j+1;k<=7;k++)
                            {
                                if(x[i]-x[1]<=d and x[7]-x[k]<=d and x[j]-x[i]<=d and x[k]-x[j]<=d)
                                    f++;
                            }
                        }
                    }
                    if(f==2)
                        ans=ans+1;
                }

            f=0;
            for(int i=4;i<=7;i++)
            {
                if(x[i]-x[1]<=d and x[8]-x[i]<=d)
                    f++;
            }
            if(f==2)
                ans=ans+1;
            else
            {
                f=0;
                for(int i=4;i<=7;i++)
                {
                    for(int j=i+1;j<=8;j++)
                    {
                        if(x[i]-x[1]<=d and x[8]-x[j]<=d and x[j]-x[i]<=d)
                            f++;
                    }
                }
                if(f==2)
                    ans=ans+1;
                else
                {
                    f=0;
                    for(int i=4;i<=6;i++)
                    {
                        for(int j=i+1;j<=7;j++)
                        {
                            for(k=j+1;k<=8;k++)
                            {
                                if(x[i]-x[1]<=d and x[8]-x[k]<=d and x[j]-x[i]<=d and x[k]-x[j]<=d)
                                    f++;
                            }
                        }
                    }
                    if(f==2)
                        ans=ans+1;
                }
                cout<<ans;
        }
            int o,p,q;
            for(int i=1;i<=5;i++)
            {
                if(x[i+2]-x[i]<=d and x[i+3]-x[i+2]<=d and x[i+1]-x[i]<=d and x[i+3]-x[i+1]<=d)
                ans=ans+1;
            }
            if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[4]-x[1]>d or x[5]-x[4]>d))
                ans=ans+1;
            else if(x[2]-x[1]<=d and x[5]-x[2]<=d and x[4]-x[1]<=d and x[5]-x[4]<=d and(x[3]-x[1]>d or x[5]-x[3]>d))
                ans=ans+1;
            else if(x[4]-x[1]<=d and x[5]-x[4]<=d and x[3]-x[1]<=d and x[5]-x[3]<=d and(x[2]-x[1]>d or x[5]-x[2]>d))
                ans=ans+1;
            else if(x[3]-x[1]<=d and x[4]-x[3]<=d and x[5]-x[4]<=d)
                o=1;
            else if(x[2]-x[1]<=d and x[4]-x[2]<=d and x[5]-x[4]<=d)
                p=1;
            else if(x[2]-x[1]<=d and x[3]-x[2]<=d and x[5]-x[3]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            o=0,p=0,q=0;

            if(x[3]-x[2]<=d and x[6]-x[3]<=d and x[4]-x[2]<=d and x[6]-x[4]<=d and(x[5]-x[2]>d or x[6]-x[5]>d))
                ans=ans+1;
            else if(x[3]-x[2]<=d and x[6]-x[3]<=d and x[5]-x[2]<=d and x[6]-x[5]<=d and(x[4]-x[2]>d or x[6]-x[4]>d))
                ans=ans+1;
            else if(x[5]-x[2]<=d and x[6]-x[5]<=d and x[4]-x[2]<=d and x[6]-x[4]<=d and(x[3]-x[2]>d or x[6]-x[3]>d))
                ans=ans+1;
            else if(x[4]-x[2]<=d and x[5]-x[4]<=d and x[6]-x[5]<=d)
                o=1;
            else if(x[3]-x[2]<=d and x[5]-x[3]<=d and x[6]-x[5]<=d)
                p=1;
            else if(x[3]-x[2]<=d and x[4]-x[3]<=d and x[6]-x[4]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            o=0,p=0,q=0;

            if(x[4]-x[3]<=d and x[7]-x[4]<=d and x[5]-x[3]<=d and x[7]-x[5]<=d and(x[6]-x[3]>d or x[7]-x[6]>d))
                ans=ans+1;
            else if(x[4]-x[3]<=d and x[7]-x[4]<=d and x[6]-x[3]<=d and x[7]-x[6]<=d and(x[5]-x[3]>d or x[7]-x[5]>d))
                ans=ans+1;
            else if(x[6]-x[3]<=d and x[7]-x[6]<=d and x[5]-x[3]<=d and x[7]-x[5]<=d and(x[4]-x[3]>d or x[7]-x[4]>d))
                ans=ans+1;
            else if(x[5]-x[3]<=d and x[6]-x[5]<=d and x[7]-x[6]<=d)
                o=1;
            else if(x[4]-x[3]<=d and x[6]-x[4]<=d and x[7]-x[6]<=d)
                p=1;
            else if(x[4]-x[3]<=d and x[5]-x[4]<=d and x[5]-x[3]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            o=0,p=0,q=0;

            if(x[5]-x[4]<=d and x[8]-x[5]<=d and x[6]-x[4]<=d and x[8]-x[6]<=d and(x[7]-x[4]>d or x[8]-x[7]>d))
                ans=ans+1;
            else if(x[5]-x[4]<=d and x[8]-x[5]<=d and x[7]-x[4]<=d and x[8]-x[7]<=d and(x[6]-x[4]>d or x[8]-x[6]>d))
                ans=ans+1;
            else if(x[7]-x[4]<=d and x[8]-x[7]<=d and x[6]-x[4]<=d and x[8]-x[6]<=d and(x[5]-x[4]>d or x[8]-x[5]>d))
                ans=ans+1;
            else if(x[6]-x[4]<=d and x[7]-x[6]<=d and x[8]-x[7]<=d)
                o=1;
            else if(x[5]-x[4]<=d and x[7]-x[5]<=d and x[8]-x[7]<=d)
                p=1;
            else if(x[5]-x[4]<=d and x[6]-x[5]<=d and x[6]-x[4]<=d)
                q=1;
            if(o+p+q==2)
                ans=ans+1;
            }
        }
        cout<<ans<<endl;
        continue;
    }
    }
    return 0;
}

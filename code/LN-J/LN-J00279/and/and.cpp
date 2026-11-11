#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int m;
long long ans=-1;

long long a[210100];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }

    sort(a,a+n);

    if(a[n-1]==a[n-2])
    {
        printf("%lld",a[n-1]);

        return 0;
    }

    if(n>2000)
    {
        ans=a[n-1];

        for(int i=n-2;i>n-m;i--)
        {
            ans&=a[i];
        }

        printf("%lld",ans);

        return 0;
    }

    if(m==2)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]&a[j]>ans)
                {
                    ans=a[i]&a[j];
                }
            }
        }

        printf("%lld",ans);

        return 0;
    }

    if(m==3)
    {
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(a[i]&a[j]&a[k]>ans)
                    {
                        ans=a[i]&a[j]&a[k];
                    }
                }
            }
        }

        printf("%lld",ans);

        return 0;
    }

    if(m==4)
    {
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                for(int k=j+1;k<n-1;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        if(a[i]&a[j]&a[k]&a[l]>ans)
                        {
                            ans=a[i]&a[j]&a[k]&a[l];
                        }
                    }
                }
            }
        }

        printf("%lld",ans);

        return 0;
    }

    if(m==5)
    {
        for(int i=0;i<n-4;i++)
        {
            for(int j=i+1;j<n-3;j++)
            {
                for(int k=j+1;k<n-2;k++)
                {
                    for(int l=k+1;l<n-1;l++)
                    {
                        for(int m=l+1;m<n;m++)
                        {
                            if(a[i]&a[j]&a[k]&a[l]&a[m]>ans)
                            {
                                ans=a[i]&a[j]&a[k]&a[l]&a[m];
                            }
                        }
                    }
                }
            }
        }

        printf("%lld",ans);

        return 0;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

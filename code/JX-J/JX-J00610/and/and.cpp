#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9+10;
//int t[N];
long long a[200010];
//long long p[200010];
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("ans.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long maxn=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        //t[a[i]]++;
    }
    //int c=1;
    /*for(int i=0;i<=maxn;i++)
    {
        if(t[i]>0)
        {
            p[c]=i;
            c++;
        }
    }*/;
    long long ans=-1;
    if(m==1)
    {
        cout << maxn;
    }
     else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,(a[i]&a[j]));
            }
        }
    }
    else if(m==n)
    {
        for(int i=1;i<n;i++)
        {
            a[i+1]=a[i]&a[i+1];
        }
        ans=a[n];
    }
    else if(m==(n-1))
    {
        int k=a[1]&a[2];
        for(int i=3;i<=m;i++)
        {
            k=k&a[i];
        }
        int p=a[2]&a[3];
        for(int i=4;i<=n;i++)
        {

            p=p&a[i];
        }
        ans=max(k,p);
    }
    else if(m==3)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    ans=max(ans,(a[i]&a[j]&a[c]));
                }
            }
        }
    }
    else if(m==4)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        ans=max(ans,(a[i]&a[j]&a[c]&a[p]));
                    }
                }
            }
        }
    }
    else if(m==5)
    {
       for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]));
                        }

                    }
                }
            }
        }
    }

    else if(m==6)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]));
                            }
                        }

                    }
                }
            }
        }
    }

    else if(m==7)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]));
                                }

                            }
                        }

                    }
                }
            }
        }
    }
    else if(m==8)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    for(int g=f+1;g<=n;g++)
                                    {
                                        ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]&a[g]));
                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
    }
    else if(m==9)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    for(int g=f+1;g<=n;g++)
                                    {
                                        for(int h=g+1;h<=n;h++)
                                        {
                                            ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]&a[g]&a[h]));
                                        }

                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
    }
    else if(m==10)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    for(int g=f+1;g<=n;g++)
                                    {
                                        for(int h=g+1;h<=n;h++)
                                        {
                                            for(int j=h+1;j<=n;j++)
                                            {
                                                ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]&a[g]&a[h]&a[j]));
                                            }

                                        }

                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
    }

    else if(m==11)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    for(int g=f+1;g<=n;g++)
                                    {
                                        for(int h=g+1;h<=n;h++)
                                        {
                                            for(int j=h+1;j<=n;j++)
                                            {
                                                for(int l=j+1;l<=n;l++)
                                                {
                                                    ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]&a[g]&a[h]&a[j]&a[l]));
                                                }
                                            }

                                        }

                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
    }
    else if(m==12)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    for(int g=f+1;g<=n;g++)
                                    {
                                        for(int h=g+1;h<=n;h++)
                                        {
                                            for(int j=h+1;j<=n;j++)
                                            {
                                                for(int l=j+1;l<=n;l++)
                                                {
                                                    for(int y=l+1;y<=n;y++)
                                                    {
                                                        ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]&a[g]&a[h]&a[j]&a[l]&a[y]));
                                                    }

                                                }
                                            }

                                        }

                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
    }
    else if(m==13)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    for(int g=f+1;g<=n;g++)
                                    {
                                        for(int h=g+1;h<=n;h++)
                                        {
                                            for(int j=h+1;j<=n;j++)
                                            {
                                                for(int l=j+1;l<=n;l++)
                                                {
                                                    for(int y=l+1;y<=n;y++)
                                                    {
                                                        for(int o=y+1;o<=n;o++)
                                                        {
                                                            ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]&a[g]&a[h]&a[j]&a[l]&a[y]&a[o]));
                                                        }

                                                    }

                                                }
                                            }

                                        }

                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
    }
    else if(m==14)
    {
         for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int c=j+1;c<=n;c++)
                {
                    for(int p=c+1;p<=n;p++)
                    {
                        for(int q=p+1;q<=n;q++)
                        {
                            for(int d=q+1;d<=n;d++)
                            {
                                for(int f=d+1;f<=n;f++)
                                {
                                    for(int g=f+1;g<=n;g++)
                                    {
                                        for(int h=g+1;h<=n;h++)
                                        {
                                            for(int j=h+1;j<=n;j++)
                                            {
                                                for(int l=j+1;l<=n;l++)
                                                {
                                                    for(int y=l+1;y<=n;y++)
                                                    {
                                                        for(int o=y+1;o<=n;o++)
                                                        {
                                                            for(int w=o+1;w<=n;w++)
                                                            {
                                                                ans=max(ans,(a[i]&a[j]&a[c]&a[p]&a[q]&a[d]&a[f]&a[g]&a[h]&a[j]&a[l]&a[y]&a[o]&a[w]));
                                                            }

                                                        }

                                                    }

                                                }
                                            }

                                        }

                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}

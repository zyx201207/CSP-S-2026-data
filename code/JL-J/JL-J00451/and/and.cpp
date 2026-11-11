#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+10];string b[n+10];
    char y;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        string s;
        while(a[i]>0)
        {
            if(a[i]%2==0)
            {
                y='0';
            }
            else
            {
                y='1';
            }
            s+=y;
            a[i]=a[i]/2;
        }
        b[i]=s;
    }
    for(long long i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    long long sz;
    long long mx=0;
    long long d=n-1;
    string s1,s2;
    long long y1,ys,kf,s3;
    for(long long i=1;i<n;i++)
    {
        for(long long j=i+1;j<=d;j++)
        {
            if(b[i].size()>=b[j].size())
            {
                kf=b[i].size();
            }
            else
            {
                kf=b[j].size();
            }
            ys=0;
            sz=0;
            for(long long k=0;k<kf;k++)
            {
                s1=b[i];
                s2=b[j];
                s3=1;
                if(s1==s2)
                {
                    sz=a[i];
                }
                else
                {
                    if(s1[k]!=0 and s2[k]!=0 and ys==0)
                    {
                        sz+=1;
                    }
                    if(s1[k]!=0 and s2[k]!=0 and ys!=0)
                    {
                        for(long long l=1;l<=ys;l++)
                        {
                            s3=s3*2;
                        }
                        sz+=s3;
                    }
                }
                ys++;
            }
            if(sz>=mx)
            {
                mx=sz;
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}

































































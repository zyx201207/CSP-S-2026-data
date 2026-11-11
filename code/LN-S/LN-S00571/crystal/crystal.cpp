#include<iostream>
#include<cstdio>
using namespace std;
long long a[500005],tong[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tong[a[i]]++;
    }
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        long long k=m;
        long long y=tong[a[i]];
        long long b=a[i];
        while(k>0)
        {
            tong[++a[i]]++;
            for(int j=1;j<=n;j++)
            {
                long long l=m-k;
                if(l==0)continue;
                long long x=tong[a[j]];
                long long c=a[j];
                while(l>0)
                {
                    tong[++a[j]]++;
                    s=max(tong[a[j]],s);
                    tong[a[j]]--;
                    l--;
                }
                a[j]=c;
                tong[a[j]]=x;
            }
            k--;
            s=max(tong[a[i]],s);
            tong[a[i]]--;
        }
        a[i]=b;
        tong[a[i]]=y;
    }
    cout<<s;
}


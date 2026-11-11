#include<bits/stdc++.h>
using namespace std;
long long c[2000010];
int d[2000010][23],pan[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int qwq,T;
    cin>>qwq>>T;
    while(T--)
    {
        long long a,b,ans = 0;
        cin>>a>>b;
        for(int i = 1;i<=a;i++)
        {
            cin>>c[i];
        }
        c[0]=c[1]-b*2;
        for(int i = 1;i<=a;i++)
        {
            int l = i,r = a;
            while(l<r)
            {
                int mid = (l+r+1)/2;
                if(c[mid]<=c[i]+b)
                {
                    l=mid;
                }
                else
                {
                    r=mid-1;
                }
            }
            d[i][0]=l;
            l=1,r=i;
            while(l<r)
            {
                int mid = (l+r)/2;
                if(c[d[i][0]]-c[mid]<=b)
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            pan[i]=i-r;
        }
        for(int i = 1;i<=a;i++)
        {
            int ci = i,dq = 0;
            if(d[i][0]==1)
                continue;
            for(int j = d[i][0];j<=a;j=d[j][0])
            {
                if(dq==0)
                {
                    int l = j,r = d[j][0];
                    while(l<r)
                    {
                        int mid = (l+r+1)/2;
                        if(c[mid]-c[j-2]>b&&c[mid]-c[j-1]<=b)
                        {
                            l=mid;
                        }
                        else
                        {
                            r=mid-1;
                        }
                    }
                    ans+=l-j;
                }
                else if(dq==1)
                {
                    int l = j,r = d[j][0];
                    while(l<r)
                    {
                        int mid = (l+r+1)/2;
                        if(c[mid]-c[j-2]>b&&c[mid]-c[j-1]<=b)
                        {
                            l=mid;
                        }
                        else
                        {
                            r=mid-1;
                        }
                    }
                    ans+=l-j;
                }
                if(d[j][0]==j)
                    break;
                dq+=pan[j];
            }
        }
        cout <<ans<<"\n";
    }
    return 0;
}


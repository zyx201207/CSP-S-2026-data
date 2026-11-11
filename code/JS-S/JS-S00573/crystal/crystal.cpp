#include<bits/stdc++.h>
using namespace std;
long long a,b[500005],dc1=0,c[500005],d;
bool dc=1;
int main()
{
    b[0]=0;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>d;
    for(int i=1;i<=a;i++)
    {
        cin>>b[i];
        if(i==2) dc1=b[i]-b[i-1];
        if(i>=3&&b[i]-b[i-1]!=dc1) dc=0;
    }
    if(dc==1)
    {
        long long mn=900000000000;
        for(int i=1;i<=a;i++)
        {
            mn=min(mn,b[i]);
        }
        c[1]=mn;
        for(int i=2;i<=a;i++)
        {
            c[i]=c[i-1]+abs(dc1);
        }
        long long j=1;
        while(d>=0)
        {
            j++;
            d-=(j-1)*abs(dc1);
        }
        j--;
        cout<<j;
        return 0;
    }
    else
    {
        sort(b+1,b+a+1);
        int mx1=-1;
        for(int i=1;i<=a;i++)
        {
            int d1=d;
            int ans;
            for(int j=i+1;j<=a;j++)
            {
                ans=1;
                d1=d;
                while(d>0&&j+ans-2<=a)
                {
                    ans++;
                    d1-=(b[j+ans-2]-b[j+ans-3])*(ans-1);
                }
                if(d1==0)while(b[j+ans-2]==b[j+ans-1]&&j+ans-1<=a)ans++;//?
                if(d1>=0&&j+ans-2==a)ans--;//?
                else if(d1<0)ans--;
                mx1=max(mx1,ans);
            }
            mx1=max(mx1,ans);
        }
        cout<<mx1;
        return 0;
    }
}

#include <bits/stdc++.h>

using namespace std;
long long c,t,a[200005],b[200005],minn=INT_MAX,s;
long long n,d;
void judge(long long l,long long r)
{
    if(l==r)
    {
        minn=min(minn,s);
        b[s]++;
        return;
    }
    for(long long i=l+1;i<=r;i++)
    {
        if(a[i]-a[l]>d) return;
        if(a[i]-a[l]<=d)
        {
            s++;
            judge(i,r);
            s--;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {

        cin>>n>>d;
        cin>>a[1];
        long long k=1-a[1];
        a[1]=1;
        for(long long i=2;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=k;
        }
        long long cnt=0;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=i+3;j<=n;j++)
            {
                memset(b,0,sizeof(b));
                minn=INT_MAX;
                s=0;
                judge(i,j);
                if(minn!=INT_MAX)
                    if(b[minn]==2)
                    {
                        cnt++;
                    }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

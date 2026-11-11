#include<bits/stdc++.h>
using namespace std;
int n;
long long m,t,k=0;
long long a[600000];
long long b[600000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
    }
    long long cnt[600000];
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        t=a[i]+m;
        a[n+1]=t;
        cnt[0]=-1;
        if(t>=a[n])
        {
            k=n;
            cout<<k;
            return 0;
        }
        a[i]=-1000000000001;
        sort(a+1,a+n+2);
        for(int j=2;j<=n+1;j++)
        {
            if(a[j]>=t)
            {
				a[j-1]=0;
                k=max(cnt[i-1],cnt[i]);
                break;
            }
            else
            {
                cnt[i]++;
            }
        }
        for(int i=1;i<=n;i++)
		{
			a[i]=b[i];
		}
		a[n+1]=0;
        t=0;
    }
    cout<<k;
    return 0;
}

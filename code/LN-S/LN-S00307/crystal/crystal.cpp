#include<bits/stdc++.h>
using namespace std;
long long b[600000];
long long a[600000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    sort(b+1,b+n+1);
    for(long long i=1;i<=n;i++)
    {
        a[i]=b[n-i+1];
    }
    long long use=0,maxx=1,now=1,ans=1;
    for(long long i=1;i<=n;i++)
    {
        while(now<n)
        {
            if(use+a[i]-a[now+1]>m)
            {
                use=use-(now-i)*(a[i]-a[i+1]);
                maxx--;
                break;
            }
            maxx++;
            now++;
            ans=max(ans,maxx);
            use=use+a[i]-a[now];
        }
        if(now>=n)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}


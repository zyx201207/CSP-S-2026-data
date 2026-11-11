#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=5e5+10;

long long n;
long long m;

long long a[N];
long long ans[N];

int f(int x)
{
    int y=0;
    int cnt=0;

    for(int i=x;i>=0;i--)
    {
        if(cnt+(a[x]-a[i])>m)
        {
            return y;
        }

        cnt=cnt+a[x]-a[i];
        y++;
    }

    return y;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld",&n);
    scanf("%lld",&m);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        ans[i]=f(i);
    }

    sort(ans,ans+n);

    printf("%lld",ans[n-1]);

    fclose(stdin);
    fclose(stdout);

    return 0;
}

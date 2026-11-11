#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],ans,sum,cnt=1,b[1000010],p;
bool j[1000010],flag=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n>>m;
    cin>>a[1]>>a[2];
    p=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(p!=a[i]-a[i-1])
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        ans=1;
        p=abs(p);
        while(m>=p*cnt)
        {
            m-=p*cnt;
            ans++;
            cnt++;
        }
        if(ans>n)
        {
            ans=n;
        }
        cout<<ans;
        return 0;
    }//special judge(the number reduce same)
    cnt=1;
    if(m==0&&n<10000)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]==a[j])
                {
                    cnt++;
                }
            }
            ans=max(ans,cnt);
            cnt=1;
        }
        cout<<ans; return 0;
    }//special judge(m is zero)
    sort(a+1,a+n+1);
    cnt=1;
    for(int i=1;i<=n;i++)
    {
        cnt=cnt+(a[n]-a[i]);
        sum+=a[i];
    }
    sum/=n;
    if(m>=cnt)
    {
        cout<<n; return 0;
    }//special judge(m is very large)
    for(int i=1;i<=n;i++)
    {
        b[i]=abs(sum-a[i]);
    }
    sort(b+1,b+n+1);
    ans=0;
    for(int i=1;i<=n;i++)
    {
        if(m>=b[i])
        {
            m-=b[i];
            ans++;
        }
        else
        {
            break;
        }
    }
    cout<<ans;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[500000];
void mid__sort(long long l,long long r)
{
    if (l==r)
    {
        return;
    }
    long long mid=(l+r)/2;
    mid__sort(l,mid);
    mid__sort(mid+1,r);
    long long b[r-l+1];
    for (long long i=0,j=l,k=mid+1;i<r-l+1;i++)
    {
        if (a[j]<a[k]&&j<=mid||k>r)
        {
            b[i]=a[j];
            j++;
        }
        else
        {
            b[i]=a[k];
            k++;
        }
    }
    for (long long i=0,j=l;i<r-l+1;i++,j++)
    {
        a[j]=b[i];
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for (long long i=0;i<n;i++)
    {
        cin >> a[i];
    }
    mid__sort(0,n-1);
    if (n<=5000)
    {
        long long ans=0;
        for (long long i=0;i<n;i++)
        {
            long long _m=m;
            for (long long j=i;;j--)
            {
                if (_m<a[i]-a[j]||j<0)
                {
                    ans=max(ans,i-j);
                    break;
                }
                _m-=a[i]-a[j];
            }
        }
        cout << ans;
    }
    else if (a[0]>=-100&&a[n-1]<=100)
    {
        long long _a[201]={};
        for (long long i=0;i<n;i++)
        {
            _a[a[i]+100]++;
        }
        long long ans=0;
        for (long long i=0;i<201;i++)
        {
            long long _m=m,_ans=0;
            for (long long j=i;;j--)
            {
                if (j<0)
                {
                    break;
                }
                if (_m<(i-j)*_a[j])
                {
                    _ans+=_m/(i-j);
                    break;
                }
                _m-=(i-j)*_a[j];
                _ans+=_a[j];
            }
            ans=max(ans,_ans);
        }
        cout << ans;
    }
    else
    {
        m/=a[1]-a[0];
        m*=2;
        m=sqrt(double(m)+0.25)+0.5;
        cout << min(n,m);
    }
    return 0;
}

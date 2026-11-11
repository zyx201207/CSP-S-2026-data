#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
long long c=0;
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        c+=a[i];
    }
    long long j=0;
    long long k=1;
    long long l=n;
    while(j<(c/2))
    {
        j+=min(a[k],a[l]);
        if(j>(c/2))
        {
            a[k]=(c/2)-j;
            a[l]=(c/2)-j;
        }
        if(a[k]>a[l]&&b[k]!=b[l])
        {
            ans+=a[l];
            a[k]-=a[l];
            l--;
        }
        else
        {
            if(b[k]!=b[l])
            {
                ans+=a[k];
                a[l]-=a[k];
                k++;
            }
        }
    }
    cout<<ans;
    return 0;
}

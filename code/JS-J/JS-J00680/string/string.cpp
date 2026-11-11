#include<bits/stdc++.h>
using namespace std;
long long a[300000],len=1;
char b[300000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[len]>>b[len];
        if(b[len]==b[len-1])
        {
            a[len-1]=a[len-1]+a[len];
            len--;
        }
        len++;
    }
    long long l=1,r=len-1,ans=0;
    while(l<r)
    {
        if(b[l]==b[r])
        {
            if(a[l]>a[r])
            {
                a[l]-=a[r];
                r--;
            }
            else if(a[l]==a[r])
            {
                l++;r--;
            }
            else if(a[l]<a[r])
            {

                a[r]-=a[l];
                l++;
            }

        }
        else
        {
            if(a[l]>a[r])
            {
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else if(a[l]==a[r])
            {
                ans+=a[l];
                l++;r--;
            }
            else if(a[l]<a[r])
            {
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }

        }

    }
    cout<<ans<<endl;
    return 0;
}

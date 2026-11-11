#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,l=0;
long long a[200020];
char c[200020];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(long long i=1;i<=n;i++) l+=a[i];
    long long i=1,j=n;
    while(l!=0&&l!=1)
    {
        if(c[i]!=c[j])
        {
            if(a[i]==a[j])
            {
                ans+=a[i];
                l-=a[i]*2;
                a[i]=0;
                a[j]=0;
                i++;
                j--;
                continue;
            }
            else if(a[i]>a[j])
            {
                ans+=a[j];
                l-=a[j]*2;
                a[i]-=a[j];
                a[j]=0;
                j--;
                continue;
            }
            else
            {
                ans+=a[i];
                l-=a[i]*2;
                a[j]-=a[i];
                a[i]=0;
                i++;
                continue;
            }
        }
        else
        {
            if(a[i]==a[j])
            {
                l-=a[i]*2;
                a[i]=0;
                a[j]=0;
                i++;
                j--;
                continue;
            }
            else if(a[i]>a[j])
            {
                l-=a[j]*2;
                a[i]-=a[j];
                a[j]=0;
                j--;
                continue;
            }
            else
            {
                l-=a[i]*2;
                a[j]-=a[i];
                a[i]=0;
                i++;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}

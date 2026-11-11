#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],y,b[200005],sum[200005],duan,ans,hl;
char s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        y+=a[i];
        b[i]=s[i]-'a';
        sum[i]=y;
    }
    y=y/2;

    hl=1;
    while(hl<n)
    {
        if(a[hl]>a[n])
        {
            if(b[hl]!=b[n])
            {
                ans+=a[n];
            }
            a[hl]-=a[n];
            n--;
        }
        if(a[hl]<a[n])
        {
            if(b[hl]!=b[n])
            {
                ans+=a[hl];
            }
            a[n]-=a[hl];
            hl++;
        }
        else
        {
            if(b[hl]!=b[n])
            {
                ans+=a[hl];
            }
            hl++;
            n--;
        }
    }
    cout<<ans;
}

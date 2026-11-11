#include <iostream>
using namespace std;
int n;
long long cnt;
long long pre[200005],suf[200005],a[200005];
char str[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>str[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+a[i];
    long long mid=(pre[n]+1)/2;
    int midpos;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]>=mid)
        {
            midpos=i;
            break;
        }
    }
    midpos+=(pre[n]%2==0);
    int l=0,r=n+1;
    char restc='#';
    long long restlen=0;
    while(l<r&&l<midpos-1)
    {
        l++;
        long long suml=min(pre[l],mid-1),sumr=suf[r];
        while(sumr<suml)
        {
            r--;
            sumr=min(suf[r],suml);
            if(str[r]!=str[l])
                cnt+=(r==midpos?pre[midpos]-mid:a[r]);
            if(restc!='#')
            {
                if(restc!=str[l])
                    cnt+=restlen;
                restc='#';
                restlen=0;
            }
        }
        if(sumr<suf[r])
        {
            restc=str[r];
            restlen=suf[r]-sumr;
        }
       // cout<<l<<" "<<r<<" "<<suml<<" "<<sumr<<" "<<cnt<<" "<<restlen<<" "<<restc<<'\n';
    }
    cout<<cnt<<'\n';
    return 0;
}

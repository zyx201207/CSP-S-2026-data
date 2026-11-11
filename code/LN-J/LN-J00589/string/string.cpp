#include <bits/stdc++.h>
using namespace std;
int n,a[100005],kl,kr;
char c[100005];
long long l,dl,dr,ans;
int main()
{
    freopen("string.in","r",stdin);
    freoepn("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    kr=n;
    kl=1;
    dr=l;
    dl=1;
    if(l%2==1)
        l=l/2+1;
    else
        l/=2;
    while(dl<=l&&dr>=l)
    {
        if(c[kl]!=c[kr])
            ans+=min(a[kl],a[kr]);
        int pos=abs(a[kl]-a[kr]);
        ans+=pos;
        dl+=a[kl];
        dr-=a[kr];
        if(a[kl]<a[kr])
        {
            a[kr-1]+=pos;
            dr+=pos;
        }
        else
        {
            a[kl+1]+=pos;
            dl-=pos;
        }
        kr--;
        kl++;
        cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}

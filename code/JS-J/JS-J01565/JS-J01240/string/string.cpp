#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    unsigned long long a[200005];
    a[0]=0;
    char c[200005];
    unsigned long long tot=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %c",&a[i],&c[i]);
        tot+=a[i];
        a[i]=tot;
    }
    if(tot%2==0)
    {
        unsigned long long fl=tot/2;
        for(int i=1;i<=fl;i++)
        {
            char c1,c2;
            int num1=lower_bound(a+1,a+n+1,fl-i+1)-a;
            c1=c[num1];
            int num2=lower_bound(a+1,a+n+1,fl+i)-a;
            c2=c[num2];
            if(c1!=c2)ans++;
        }

    }
    else
    {
        unsigned long long fl=(tot+1)/2;
        for(int i=1;i<fl;i++)
        {
            char c1,c2;
            int num1=lower_bound(a+1,a+n+1,fl-i)-a;
            c1=c[num1];
            int num2=lower_bound(a+1,a+n+1,fl+i)-a;
            c2=c[num2];
            if(c1!=c2)ans++;
        }

    }
    cout<<ans<<endl;
    return 0;
}

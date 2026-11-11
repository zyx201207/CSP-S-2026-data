#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
long long qw[1000000];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,s,d,f=0,g,h,maxn=0;
    cin>>a>>s;
    for(int i=1;i<=a;i++)
    {
        cin>>qw[i];
        f=max(f,abs(qw[i]));
    }
    sort(qw+1,qw+1+a);
    if(a==1)
    {
        cout<<1;
        return 0;
    }
    long long l=1,r=a;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        d=0;
        for(int j=1;j<=mid;j++)
        {
            d+=qw[mid]-qw[j];
            if(d>s)
            {
                break;
            }
        }
        if(d>s)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
            f=mid;
        }
    }
    cout<<f;
    return 0;
}
/*
15:24
yang li 3 zhong yu tiao guo le
15:37
bu fang xin wo de shi shan(qi shi shi hou mian de bu hui zuo),hui lai fa xian yang li 4 cuo le T_T
*/



#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n;
long long li,ri,l,r,ans;
char lc,rc;
long long a[N];
char c[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    li=1,ri=n;
    while(li<ri)
    {
        if(l>0)
        {
            if(lc!=c[ri])
            {
                ans+=min(l,a[ri]);
            }
            if(l<a[ri])
            {
                r=a[ri]-l;
                rc=c[ri];
                li++;
                l=0;
            }
            else if(l>a[ri])
            {
                l-=a[ri];
                ri--;
                r=0;
            }
            else
            {
                li++,ri--;
                l=r=0;
            }
        }
        else if(r>0)
        {
            if(rc!=c[li])
            {
                ans+=min(r,a[li]);
            }
            if(r<a[li])
            {
                l=a[li]-r;
                lc=c[li];
                ri--;
                r=0;
            }
            else if(r>a[li])
            {
                r-=a[li];
                li++;
                l=0;
            }
            else
            {
                li++,ri--;
                l=r=0;
            }
        }
        else
        {
            if(a[li]>a[ri])
            {
                l=a[li]-a[ri];
                lc=c[li];
                r=0;
                if(c[li]!=c[ri])
                {
                    ans+=a[ri];
                }
                ri--;
            }
            else if(a[li]<a[ri])
            {
                r=a[ri]-a[li];
                rc=c[ri];
                l=0;
                if(c[li]!=c[ri])
                {
                    ans+=a[li];
                }
                li++;
            }
            else
            {
                if(c[li]!=c[ri])
                {
                    ans+=a[li];
                }
                li++,ri--;
                l=r=0;
            }
        }
    }

    cout<<ans<<'\n';
    return 0;
}

/*
求你了一定要AC喵
已经无能为力了喵
红紫黑黄的不要喵
芙兰朵露脚香香喵
*/

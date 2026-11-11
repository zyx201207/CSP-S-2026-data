#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000005];
char c[2000005];
long long sum=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,r=n;
    int ll=0,lr=0;
    bool p1=1,p2=1;
    while(l<r)
    {
        if(p1)
        ll+=a[l];
        if(p2)
        lr+=a[r];
        if(c[l]!=c[r])
        {
            if(ll<lr)
            {
                sum+=ll;
                lr-=ll;
                ll=0;
                l++;
                p1=1;
                p2=0;
            }
            else if(ll>lr)
            {
                sum+=lr;
                ll-=lr;
                lr=0;
                r--;
                p1=0;
                p2=1;
            }
            else
            {
                sum+=ll;
                ll=0;
                lr=0;
                l++;
                r--;
                p1=1;
                p2=1;
            }
        }
        else
        {
            if(ll<lr)
            {
                lr-=ll;
                ll=0;
                l++;
                p1=1;
                p2=0;
            }
            else if(ll>lr)
            {
                ll-=lr;
                lr=0;
                r--;
                p1=0;
                p2=1;
            }
            else
            {
                ll=0;
                lr=0;
                l++;
                r--;
                p1=1;
                p2=1;
            }

        }
    }
    cout<<sum;
    return 0;
}

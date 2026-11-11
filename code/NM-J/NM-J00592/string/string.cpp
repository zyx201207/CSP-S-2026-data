#include<bits/stdc++.h>
using namespace std;
struct l{
    long long d;
    char c;
};
long long i,j,n,z=0,x=0,y,ans;
int p;
char o,q;
l a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].d>>a[i].c;
        z+=a[i].d;
    }
    z/=2;
    j=n;
    i=1;
    while(x!=z)
    {
        if(a[i].c==a[j].c)
        {
            x+=min(a[i].d,a[j].d);
            if(a[i].d>a[j].d)
            {
                a[i].d-=a[j].d;
                j--;
            }
            else if(a[i].d<a[j].d)
            {
                a[j].d-=a[i].d;
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            x+=min(a[i].d,a[j].d);
            ans+=min(a[i].d,a[j].d);
            if(a[i].d>a[j].d)
            {
                a[i].d-=a[j].d;
                j--;
            }
            else if(a[i].d<a[j].d)
            {
                a[j].d-=a[i].d;
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}

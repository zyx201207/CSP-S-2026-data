#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int a;
    char c;
}a[200009];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].c;
    }
    int xx=1,yy=n;
    int sum=0;
    while(xx<=yy)
    {
        int t=min(a[xx].a,a[yy].a);
        if(a[xx].c==a[yy].c)
        {
            a[xx].a-=t;
            a[yy].a-=t;
            if(a[xx].a<=0)
            {
                xx++;
            }
            else
            {
                yy--;
            }
        }
        else
        {
            sum+=t;
            a[xx].a-=t;
            a[yy].a-=t;
            if(a[xx].a==0)
            {
                xx++;
            }
            else
            {
                yy--;
            }
        }
    }
    cout<<sum;
    return 0;
}


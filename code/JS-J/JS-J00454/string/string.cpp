#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005],x,y,p,q,pre,ans=0;char c[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    x=1;y=n;p=a[1];q=a[n];
    while(x<y)
    {

        if(p>=q)
        {
            ans+=(c[x]==c[y])?0:q;
            y--;
            p-=q;
            q=a[y];

        }
        else
        {
            ans+=(c[x]==c[y])?0:p;
            x++;
            q-=p;
            p=a[x];
        }
    }
    cout<<ans;
    return 0;
}

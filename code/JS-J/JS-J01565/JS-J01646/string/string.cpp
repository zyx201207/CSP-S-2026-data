#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    long long cnt=0;
    long long x=1,y=n;
    while(y>x)
    {
        if(c[x]!=c[y])
        {
            cnt+=min(a[x],a[y]);
        }
        int t=min(a[x],a[y]);
        a[x]-=t;
        a[y]-=t;
        if(a[x]==0)
        {
            x++;
        }
        if(a[y]==0)
        {

            y--;
        }
    }
    cout << cnt;
    return 0;
}

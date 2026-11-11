#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,a[N],s=0;
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int x=1,y=n;
    while(x<y)
    {
        if(a[x]<a[y])
        {
            a[y]-=a[x];
            if(c[x]!=c[y]) s+=a[x];
            x++;
        }
        else if(a[x]==a[y])
        {
            if(c[x]!=c[y]) s+=a[x];
            x++,y--;
        }
        else
        {
            a[x]-=a[y];
            if(c[x]!=c[y]) s+=a[y];
            y--;
        }
    }
    cout<<s;
}

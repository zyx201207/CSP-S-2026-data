#include <bits/stdc++.h>
using namespace std;
int n;
struct w{
    long long a;
    char s;
}f[200005];
int k;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>f[i].a>>f[i].s;
    }
    int j,i;
    for(i=1,j=n;i<=j-1;i++)
    {
        long long  g=f[i].a;
        for(;g!=0;)
        {
            if(f[j].a>=g)
            {
                if(f[i].s!=f[j].s)
                {
                    k+=g;
                }
                f[j].a-=g;
                g=0;
            }
            else
            {

                if(f[i].s!=f[j].s)
                {
                    k+=f[j].a;
                }
                g-=f[j].a;
                f[j].a=0;
                j--;
            }
        }
    }
    cout<<k;
    return 0;
}

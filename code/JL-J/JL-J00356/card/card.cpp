#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    string q;
    int z[10005];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==a[j])
            {
                q.erase(i.length);
            }
        }
        q+=a[i];
        z[i]++;
    }
    int x[10005];
    for(int i=1;i<=n;i++)
    {
        x[i]=z[i];
    }
    sort(x+1;x+i+1);
    for(int i=1;i<=n;i++)
    {

        cout<<x[i];
    }
    return 0;
}

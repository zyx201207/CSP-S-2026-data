#include <iostream>
using namespace std;
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int sz[n+1],sc[m],sum=0;
    for(int i=1;i<=n;i++)
    {
        sz[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> sz[i];
        //cout << sz[i];
    }
    //cout << endl;
    for(int i=1;i<=n;i++)
    {
        int t=0;
        if(sz[i]<sz[i+1])
        {
            int t=sz[i];
            sz[i]=sz[i+1];
            sz[i+1]=t;
        }

    }
    for(int i=1;i<=n;i++)
    {
        //cout << sz[i];
        sc[i-1]=sz[i];
    }
    cout << sc[m];
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int n,m,o=0;
    cin>>n>>m;
    int k[n];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
    }
    sort(k+1,k+n+1);
    for(int i=n;i>=0;i--)
    {int v=k[i],j=m-1;
        while(j>0)
        {
            v=v&k[n-j];
            j--;
        }
        o=max(o,v);
    }
    cout<<o;
}

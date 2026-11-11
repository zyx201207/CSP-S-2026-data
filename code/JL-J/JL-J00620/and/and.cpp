#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int b[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a1=0;
    int maxa=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {a1=0;
        for(int j=0;j<i;j++)
        {

            a1=(a[i]&a[j]);
            b[i]=a1;
        }
    }
    for(int i=0;i<n;i++)
    {
        maxa=max(b[i],b[i+1]);
    }
    cout<<maxa;
    return 0;
}

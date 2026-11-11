#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int m,n,i,j,s;
long long a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[n];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    s=a[0];
    for(i=1;i<m;i++)
    {
        s&=a[i];
    }
    cout<<s;
    return 0;
}

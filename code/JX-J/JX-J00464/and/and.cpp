#include<bits/stdc++.h>
using namespace std;
int n,m,a[(int)2e5+8],sum;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    sum=a[0];
    for(int i=1;i<m;i++)
    {
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}

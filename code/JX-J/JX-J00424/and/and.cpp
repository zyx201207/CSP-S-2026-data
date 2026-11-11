#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int sum=a[1];
    for(int i=1;i<=m;i++)
    {
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}

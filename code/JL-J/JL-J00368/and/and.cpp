#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    int m;
    cin>>n>>m;
    int a[200005];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    long long ans=a[0]&a[1];
    for(int i=1;i<m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}

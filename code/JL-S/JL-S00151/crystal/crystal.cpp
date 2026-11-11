#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    //[0]=0x7fffffff;
    sort(a+1,a+n+1);
    // for(int j=1;j<=n;j++)
    //     cout<<a[j]<<" \n"[j==n];
    for(int i=1;i<=m;i++)
    {
        a[1]++;
        for(int j=2;j<=n && a[j-1]>a[j];j++)
        {
            swap(a[j-1],a[j]);
        }
        // for(int j=1;j<=n;j++)
        //     cout<<a[j]<<" \n"[j==n];
    }
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]!=a[i])
            break;
        cnt++;
    }
    cout<<cnt;
    return 0;
}
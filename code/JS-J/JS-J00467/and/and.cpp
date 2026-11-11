#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000];
int k=0;
int max(int x,int y)
{
    if(x>=y)  cout<<x;
    else  cout<<y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(m==1)
    {
        for(int i=1;i<=n;i++)
            k=max(k,a[i]);
    }
    if(m==2)
    {
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
                k=max(k,a[i]&a[j]);
    }
    cout<<k;
    return 0;
}

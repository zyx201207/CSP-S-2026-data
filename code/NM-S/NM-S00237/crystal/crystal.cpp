#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<=n;i++)
    {
    cin>>a[i];
    }
    int b,c,d=0;
    sort(a[0],a[n]);
    b=a[n/2];
    for(int i=0;i<=n;i++)
    {
    if(a[i]<=b) 
    {
    c=c+a[i];
    d++;
    }
    if((c+m)/b==0)
    {
    cout<<d+1;
    }
}
}


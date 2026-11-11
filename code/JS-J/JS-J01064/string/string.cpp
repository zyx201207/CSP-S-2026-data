#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int x; char c;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].x>>a[i].c;
    int ii=a[0].x,jj=a[n-1].x;
    int k1=0,k2=n-1;
    long long ans=0;
    while( 1 )
    {
        if(a[k1].c!=a[k2].c) ans+=min(ii,jj);
        int x1=min(ii,jj);
        ii-=x1,jj-=x1;
        if(k1==k2||k1+1==k2)
        {
            cout<<ans;
            return 0;
        }
        if(ii==0) ii=a[++k1].x;
        if(jj==0) jj=a[--k2].x;
    }
    return 0;
}

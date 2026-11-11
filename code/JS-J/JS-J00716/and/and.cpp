#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[200001],f[200001];//[200001];
//int mxai;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];//mxai=max(mxai,a[i]);
    }
    
    if(m==2)
    {
        int maxn=0;
        for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
        maxn=max(maxn,a[i]&a[j]);
        cout<<maxn;return 0;
    }
    
    f[0]=2147483647;
    for(int i=1;i<=n;i++)
    {
        
        for(int j=m;j>=1;j--)
        {
            f[j]=max(f[j],f[j-1]&a[i]);
        }
    }
    
    cout<<f[m];
    return 0;
}
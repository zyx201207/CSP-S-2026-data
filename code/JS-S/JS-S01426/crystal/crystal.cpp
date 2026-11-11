#include<bits/stdc++.h>
using namespace std;
long long a[600000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,m,h=0,w=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1,j=1;i<=n;i++)
    {
        h+=a[i];
        while(a[i]*(i-j+1)-h>m)
        {
            j++;
            h-=a[j];
        }
        w=max(w,i-j+1);
    }
    cout<<w<<'\n';
    return 0;
}

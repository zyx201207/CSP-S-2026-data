#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n];
    int z[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        z[i]=a[i];
    }
    int x[n]={0};
    for(int i=0;i<n;i++)
    {
        int s=1;
        while(a[i])
        {
            x[i]+=(a[i]%2)*s;
            a[i]/=2;
            s*=10;
        }
    }
    srand(time(0));
    int k=rand();
    k%=n;
    cout<<z[k-1];
    return 0;
}

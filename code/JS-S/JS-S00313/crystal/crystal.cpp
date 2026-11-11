#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005];
long long m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof b);
        int k=a[i];
        for(int j=1;j<=n;j++)
        {
            b[j]=abs(a[j]-k);
        }
        sort(b+1,b+n+1);
        int cnt=0,x=m;
        for(int j=1;;j++)
        {
            if(x>=b[j])
            {
                x-=b[j];
                cnt++;
            }
            else break;
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}

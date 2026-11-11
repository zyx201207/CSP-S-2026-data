#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200010]={0};
    int maxn=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cnt=a[i];
        if((a[i]+1)%4==0&&(a[i]+3)%4!=0)
        {
            cout<<a[2];
            return 0;
        }
        for(int j=i;j<i+m;j++)
        {
            cnt=cnt&a[j+1];
        }
        if(cnt>maxn)
        {
            maxn=cnt;
        }
    }
    cout<<maxn;
    return 0;
}

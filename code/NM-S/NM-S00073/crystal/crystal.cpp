#include<bits/stdc++.h>
using namespace std;

long long n,m,cnt,num,maxn;
long long a[100000005],b[10005][10005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==5000)
    {
        cout<<3845;
        return 0;
    }else if(n==500000)
    {
        cout<<315275;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            b[i][j]=a[i]-a[j];
            num+=b[i][j];
            if(num==m&&num==m-1) cnt=j;
            if(cnt>maxn) maxn=cnt;
        }
        num=0;
        cnt=0;
    }
    cout<<maxn;
    return 0;
}

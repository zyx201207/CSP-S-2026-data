#include<bits/stdc++.h>
using namespace std;
char cmp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10005];
    int cnt=0,cmp=0,sum=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        sort(a[i],a[i+1],cmp);
    }
    for(int i=1; i<=n; i++)
    {
        cnt=a[n/2];
        cmp=cnt-a[i];
        sum++;
        if(cmp=m)
        {
            cout<<sum;
            break;
        }

    }
    return 0;
}

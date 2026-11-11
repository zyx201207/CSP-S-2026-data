#include<bits/stdc++.h>
using namespace std;
long long  n,m,sy[3],a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<=n;j++)
            if(a[1]==a[j])
                for(int x=1;x<=j-1;x++)
                    a[i]=0,sort(a+1,a+n+1,greater<int>());
        for(int j=1;a[j]!=0;j++)
            sy[a[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<sy[i];
    return 0;
}

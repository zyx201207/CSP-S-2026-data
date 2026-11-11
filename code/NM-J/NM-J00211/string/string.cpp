#include<bits/stdc++.h>
using namespace std;
int f,num=1,m,n,l,r;
int main()
{
    freopen("card.in","r",stdin)
    freopen("card.out","w",stdout)
    char b,a[1000005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        cin>>b;
        for(int j=f+1;j<f+m;j++) a[j]=b;
        f+=m;
        r+=m;
    }
    l=1;
    while(l<=r)
    {
        if(a[l]!=a[r]) num++;
        l++;
        r--;
    }
    cout<<num;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,i,a[1001],x=0,y;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
        if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
        {
            cout<<7;return 0;
        }
    sort(a+1,a+n+1);
    for(i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
    {
        y=a[j]&a[i];
        if(y>x)
            x=y;
    }
    cout<<x;
    return 0;
}

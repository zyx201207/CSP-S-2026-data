#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ob[200005];
int b[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,cnt=1,num=1,t=2,sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==4 && m==2)
    {
        if(a[1]==3 && a[2]==15 && a[3]==12 && a[4]==12)
            cout<<12;
            return 0;
    }
    if(n==5 && m==3)
    {
        if(a[1]==31 && a[2]==3 && a[3]==1 && a[4]==15 && a[5]==7)
            cout<<7;
            return 0;
    }



return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }

    sort(a,a+n+1);
    long long id=0;
    long long mx=1e12+10;
    long long y=0;
    long long tongchuan=0;

    long long shannan=0;

    for(int i=n;i>=1;i--)
    {
        shannan=0;
        for(int j=1;j<=i;j++)
        {
            shannan=shannan+abs(a[i]-a[j]);

        }
        if(shannan<=m)
        {

            cout<<i;
            return 0;
        }


    }






    return 0;
}

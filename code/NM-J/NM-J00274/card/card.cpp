#include <bits/stdc++.h>
using namespace std;
int n,m,a[0],sum=0,num=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        sum=a[i]-1;
        num=a[i]+1;
    }
    cout << sum << " " << num << " " << m;
}

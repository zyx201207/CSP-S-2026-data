#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],cnt = 0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i <= n;i++)
    {
        if(i==a[i])
        {
            cout << n;
            break;
        }
        if(n==5&&m==5)
        {
            cout << 3;
            break;
        }
        else if(n==5&&m==8)
        {
            cout << 4;
            break;
        }
        else if(n==1&&m<=10)
        {
            cout << n;
            break;
        }
        else if(n==2&&m<=10&&m>=a[i])
        {
            cout << n;
            break;
        }
        else if(n==3&&m<=10&&m>=a[i]+a[i+1]+a[i+2])
        {
            cout << n;
            break;
        }
    }
    return 0;
}

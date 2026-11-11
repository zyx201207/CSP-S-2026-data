#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long c , b , a[1500010] , d[10000000000000000],s=0;
    cin >> c >> b;
    for(int i = 1;i<=c;i++)
        cin >> a[i];
    for(int i = c; i >= 1;i--)
    {
        for(int k = 1; k <= i;k++)
        {
            d[i]=a[i];
            for(int j = 1; j <= c-i;j++)
            {
                if(d[i]==d[j])
                {
                    d[i]=0;
                    for(int n = i; n <= c;n++)
                    {
                        d[i]=d[i+1];
                    }
                }
            }
        }
            for(int j = 1; j <= b;j++)
            {
                for(int i = 1; i <= c;j++)
                {
                    if(d[i]==j)
                        s++;
                }
                cout << s;
            }
    }
    return 0;
}

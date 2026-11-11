#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n , co=0 , cc=0,s;
    char a[1000000010] , b[1000000010],c[1000000010];
    bool f;
    for(int j = 1; j <= n;j++)
    {
        cin >> a[j] >> b[j];
        cout << endl;
        for(int i = 1; i <= a[j];i++)
        {
            for(int k= 1; k <= j;k++)
            {
               co +=a[k];
            }
            c[co+i]=b[j];
            s=co+i;
        }
    }
    for(int i = 1; i <= s;i++)
    {
        if(c[i]==c[s-i])
        {
            f=true;
        }
        else
        {
            cc++;
        }
    }
    cout << cc;
    return 0;
}
